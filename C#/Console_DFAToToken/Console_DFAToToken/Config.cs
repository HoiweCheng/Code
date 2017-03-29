using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
namespace Console_DFAToToken
{
    static class Config
    {
        public static CharClass SetCharClass()
        {
            CharClass charclass = new CharClass();
            XmlDocument configDoc = new XmlDocument();
            configDoc.Load("E:\\Code\\ProjectByMyself\\Console_DFAToToken\\Console_DFAToToken\\config.xml");
            XmlElement rootElem = configDoc.DocumentElement;
            XmlNodeList charset = rootElem.GetElementsByTagName("charset");
            XmlNodeList itemsOfCharset = ((XmlElement)charset[0]).GetElementsByTagName("item");//
            
            foreach(XmlNode node in itemsOfCharset)
            {
                int index =int.Parse(((XmlElement)node).GetAttribute("index"));
                string chars = node.InnerText;
                charclass.SetCharClass(chars, index);                 
            }
            return charclass;
        }

        public static DFA GetDFASetting()
        {
            DFA dfa = new DFA();
            XmlDocument configDoc = new XmlDocument();
            configDoc.Load("E:\\Code\\ProjectByMyself\\Console_DFAToToken\\Console_DFAToToken\\config.xml");
            XmlElement root = configDoc.DocumentElement;
            XmlNodeList dfaConfig = root.GetElementsByTagName("DFA");
            XmlNodeList itemOfDfa = ((XmlElement)dfaConfig[0]).GetElementsByTagName("item");
            
            foreach(XmlNode node in itemOfDfa)
            {
                int current = int.Parse(((XmlElement)node).GetAttribute("current"));
                int next = int.Parse(((XmlElement)node).GetAttribute("next"));
                int nextstate = int.Parse(node.InnerText);
                dfa.SetDFA(current, next, nextstate);
            }
            return dfa;
        }
        public static List<string> GetKeyWords()
        {
            List<string> keyWords = new List<string>();
            XmlDocument configDoc = new XmlDocument();
            configDoc.Load("E:\\Code\\ProjectByMyself\\Console_DFAToToken\\Console_DFAToToken\\config.xml");
            XmlElement root = configDoc.DocumentElement;
            XmlNodeList keyword = root.GetElementsByTagName("keyword");
            XmlNodeList items = ((XmlElement)keyword[0]).GetElementsByTagName("item");
            
            foreach(XmlNode node in items)
            {
                keyWords.Add(node.InnerText);
            }
            return keyWords;            
        }
    }
}
