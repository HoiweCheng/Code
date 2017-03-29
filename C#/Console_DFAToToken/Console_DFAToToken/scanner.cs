using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_DFAToToken
{
    sealed class Scanner
    {
        public List<Token> tokens;
        private DFA dfa;
        private CharClass charclass;
        private List<string> keywords;
        public Scanner()
        {
            tokens = new List<Token>();
            dfa = Config.GetDFASetting();
            charclass = Config.SetCharClass();
            keywords = Config.GetKeyWords();
        }
        public void AcceptString(string context)
        {            
            TokenType tempType = TokenType.DEFULT;
            int current = 0;
            for (int i = 0; i < context.Length; )
            {
                string temp="";
                current = 0;
                if (i == 11)
                    break;
                while((i < context.Length)&&(dfa.GetNextState(current, charclass.GetIndex(context[i])) != 0))
                {                    
                    temp += context[i];
                    switch(dfa.GetNextState(current, charclass.GetIndex(context[i])))
                    {
                        case 0:
                            tempType = TokenType.DEFULT;
                            break;
                        case 1:
                            tempType = TokenType.WORD;
                            break;
                        case 2:
                            tempType = TokenType.INT;
                            break;
                        case 3:
                            tempType = TokenType.FLOAT;
                            break;
                        case 4:
                            tempType = TokenType.SPACE;
                            break;
                        case 5:
                            tempType = TokenType.STRING;
                            break;
                        case -1:
                            tempType = TokenType.ERROR;
                            break;
                        default:
                            tempType = TokenType.OPERATOR;
                            break;
                    }
                    current = dfa.GetNextState(current, charclass.GetIndex(context[i]));                    
                    ++i;

                    if (tempType == TokenType.ERROR)
                        break;                  
                }                       
                tokens.Add((new Token(temp, tempType)));
            }

            foreach(Token temp in tokens)
            {
                if(temp.Type == TokenType.WORD)
                {
                    if(keywords.Contains(temp.Description))
                    {
                        temp.Type = TokenType.KEYWORD;
                    }
                }
            }
        }        
    }
}
