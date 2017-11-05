using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.Net.Sockets;
using System.Net;
using System.Threading;

namespace PC_socket
{
    public partial class iwinRobot : Form
    {
        static bool isConnected = false;
        Robot robot;
        TelnetConnection clientTelnet;

        public iwinRobot()
        {
            robot = new Robot();
            
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            if (!isConnected)
            {
                //string ip_string = this.IPTextBox.Text;
                string ip_string = "192.168.1.20";
                //string port_string = this.PortTextBox.Text;
                string port_string = "23";
                if (!IsIPAddress(ip_string))
                {
                    this.RecordTextBox.AppendText(">> 请输入正确的ip格式\n");
                }
                else
                {
                    int port_number = Convert2Port(port_string);
                    if (port_number >= 0)
                    {
                        string s = "";
                        s = robot.Initialize(ip_string, port_number);
                        clientTelnet = new TelnetConnection(ip_string,port_number);
                        //clientTelnet.Login()

                        if (robot.IsConnected)
                        {
                            this.RecordTextBox.AppendText(">>连接服务器成功\n");
                           this.RecordTextBox.AppendText(">>" + s + '\n');
                            isConnected = true;
                            Thread.Sleep(50);
                            this.ConnectButton.Text = "断开连接";
                            this.IPTextBox.Enabled = false;
                            this.PortTextBox.Enabled = false;
                        }
                        else
                        {
                            this.RecordTextBox.AppendText(">>连接服务器失败，请检查设置\n");
                        }
                    }
                    else
                    {
                        this.RecordTextBox.AppendText(">>无效端口\n");
                        // -2 不是数字
                        // 数字不在端口范围内
                    }
                }
            }
            else
            {
                robot.Disconnect();
                this.IPTextBox.Enabled = true;
                this.PortTextBox.Enabled = true;
                this.RecordTextBox.AppendText(">>断开与机器人连接\n");
                this.ConnectButton.Text = "连接";
                isConnected = false;
            }
        }

        private int Convert2Port(string port_string)
        {
            if (IsInteger(port_string))
            {
                int port_number = int.Parse(port_string);
                if (port_number > 65535 || port_number < 0)
                    return -1;
                else
                    return port_number;
            }
            else
                return -2;
        }

        public static bool IsIPAddress(string ip)
        {
            //判断是否为IP
            return Regex.IsMatch(ip, @"^((2[0-4]\d|25[0-5]|[01]?\d\d?)\.){3}(2[0-4]\d|25[0-5]|[01]?\d\d?)$");
        }
        public static bool IsInteger(string value)
        {
            return Regex.IsMatch(value, @"^[+-]?\d*$");
        }

        private void SendButton_Click(object sender, EventArgs e)
        {
            String command = this.CommandTextBox.Text;
            if (command.Length == 0)
            {
                robot.SendCMD("");
                this.RecordTextBox.AppendText(">\n");
            }
            else
            {
                //clientTelnet.WriteLine(command);
                string response = robot.SendCMD(command);
                this.RecordTextBox.AppendText(">>" + command + '\n');
                this.CommandTextBox.Clear();
                if(response != null)
                    this.RecordTextBox.AppendText(response);
            }
            }

        private void button2_Click(object sender, EventArgs e)
        {
            string res = robot.DoTask();
            this.RecordTextBox.AppendText(res);

        }
    }
}

