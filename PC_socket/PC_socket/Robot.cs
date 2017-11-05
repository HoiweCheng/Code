using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

namespace PC_socket
{
    class Robot
    {
        TelnetConnection telNet;
        public Robot()
        { }
        public bool IsConnected
        {
            get { return telNet.IsConnected; }
        }
        public string Initialize(string ipAddress, int port)
        {
            telNet = new TelnetConnection(ipAddress, port);
            Thread.Sleep(100);
            string response = telNet.Login("as", 200);
            Thread.Sleep(100);
            response += telNet.Read();
            return response;
        }
        public void Disconnect()
        {
            telNet.DisConnect();
        }
        public string Read()
        {
            try
            {
                return telNet.Read();
            }
            catch
            {
                return "Error in Read() 连接出现问题，请重试\n";
            }
        }
        public string SendCMD(string cmd)
        {
            try
            {
                telNet.WriteLine(cmd);
                Thread.Sleep(100);
                string response = telNet.Read();
                if (telNet.IsConnected && telNet.dataAvaliable)
                {
                    response += Read();
                }
                return response;
            }
            catch
            {
                return "Error in SendCMD() 连接出现问题，请重试\n";
            }                
        }
        public string GetCurPos()
        {
            try
            {
                telNet.WriteLine("");
                telNet.WriteLine("here p");
                Thread.Sleep(30);
                string response = telNet.Read();
                return PrasePoseResponse(response);
            }
            catch
            {
                return "Error in GetCurPos() 连接出现问题，请重试\n";
            }
        }
        public string Move2Dst(string dst)
        {
            string curPos = GetCurPos();         
            telNet.WriteLine("");
            if (curPos == "error")
                return "Error in Move2Dst()\n"+curPos;
            else if(curPos == dst)
            {
                return "";
            }
            else
            {
                SendCMD("point p");
                SendCMD(dst);
                SendCMD("");
                string response = SendCMD("do jmove p");
                while(true)
                {
                    response += Read();
                    if (response.Contains("动作结束"))
                        break;
                }
                return response;
            }
        }
        public string MoveSomeDistance(int axisNum, int distance)
        {
            string dst ="";
            string[] curPos = GetCurPos().Split(',');

            for (int i = 0; i < 6; ++i) 
            {
                if (i == axisNum)
                    dst += (distance+curPos[i]).ToString() + ',';
                else
                    dst += curPos[i]+',';
            }
            return Move2Dst(dst.Remove(dst.Length -1));
        }
        public void SetSpeed(string speed)
        {
            try
            {
                SendCMD("speed " + speed);
            }
            catch
            {

            }
        }
        public void DoAction(string ioPort)
        {
            SendCMD("signal " + ioPort);
        }
        public void StopAction(string ioPort)
        {

        }
        public string DoTask()
        {
            /*string curpos = GetCurPos();
             SendCMD("");
             string midPoint1 = "";
             string response = Move2Dst(midPoint1);
            */
            string response = SendCMD("execute main2");
            while(true)
            {
                response += Read();
                if (response.Contains("程序结束"))
                    return "程序结束";
            }

        }

        private string PrasePoseResponse(string response)
        {
            if (response.Length>0)
            {
                string[] temp = response.Split(" \r\n".ToCharArray());
                string pos = "";
                foreach(var a in temp)
                {
                    if (IsNumberical(a))
                        pos += a + ',';
                }
                return pos.Remove(pos.Length - 1);
            }
            else
            {
                return "error in PrasePos()\n";
            }
        }
        private bool IsNumberical(string a)
        {
            return Regex.IsMatch(a, "^([0-9]{1,}[.][0-9]*");
        }
    }
}
