using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Console_xml
{
    static class Config
    {
        static void GetDFASetting()
        {
            DFA dfa = new DFA();
            XmlDocument config = new XmlDocument();
            config.Load("test.xml");
            XmlElement root = config.DocumentElement;
            XmlNodeList DFAconfig = root.SelectNodes("/config/DFA");
        }
        public static CharClass SetCharClass()
        {
            CharClass charclass = new CharClass();
            XmlDocument configDoc = new XmlDocument();
            configDoc.Load("E:\\Code\\C#\\Console_test\\Console_xml\\test.xml");
            XmlElement rootElem = configDoc.DocumentElement;
            XmlNodeList charset = rootElem.GetElementsByTagName("charset");
            XmlNodeList itemsOfCharset = ((XmlElement)charset[0]).GetElementsByTagName("item");//

            foreach (XmlNode node in itemsOfCharset)
            {
                int index = int.Parse(((XmlElement)node).GetAttribute("index"));
                string chars = node.InnerText;
                charclass.SetCharClass(chars, index);
            }
            return charclass;
        }
    }
}
