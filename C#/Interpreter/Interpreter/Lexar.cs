using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter.Scanner
{
    enum State
    {
        Begin, Word, String, Int, Float, Operator, Space, End, Error
    }
    class Lexar
    {
        public List<Token> TokenCollection {get; private set;}
        private char[] characters;
        private HashSet<string> Operators;
        private HashSet<string> KeyWords;
        private TokenType LastLetter(char item)
        {
            if (item >= '0' && item <= '9')
                return TokenType.INT;
            else if (item >= 'a' && item <= 'z')
                return TokenType.WORD;
            else if (item >= 'A' && item <= 'Z')
                return TokenType.WORD;
            else if (Operators.Contains(item.ToString()))
                return TokenType.OPERATOR;
            else
                return TokenType.DEFULT;
        }
        public Lexar()
        {
            TokenCollection = new List<Token>();
            Operators = new HashSet<string>() 
            {"+","++","+=","-","--","-=","*","*=","/","/=",
             "%","%=","=","!","!=",">","<",">=","<=",
             "(",")","[","]","|","||","&", "&&"};
            KeyWords = new HashSet<string>()
            {"int", "float", "string", "void", "if", 
             "else", "begin", "end", "switch", "case",
             "break", "default", "for", "while"
            };
            characters = null;
        }

        private char ReadNextChar(int index)
        {
            return characters[index];
        }
        private bool IsKeyWord(Token item)
        {
            if (item.type == TokenType.WORD)
            {
                if (KeyWords.Contains(item.Description))
                    return true;
                else
                    return false;
            }
            else
                return false;
           
        }
        private void AddToTokenCollection(string description, TokenType type, int linenumber)
        {
            Token tokenTemp = new Token(description, linenumber, type);
            TokenCollection.Add(tokenTemp);
        }
        public void Scaner(string text)
        {
             characters = text.ToCharArray();
             Analyse();
          //  return characters;
        }
        private void Analyse()
        {
            int indexOfCh = 0;
            int lineNumber = 1;
            State state = State.Begin;
            char character = ReadNextChar(indexOfCh);
            string buffer = null;
            
            while (state != State.End)
            {                
                if (indexOfCh < characters.Length)
                    character = ReadNextChar(indexOfCh);
                else
                {
                    state = State.End;
                 //   break;
                }

                switch (state)
                {
                    case State.Begin:
                        #region DFA_State--Begin
                        {
                      //      if (indexOfCh >= characters.Length)
                               
                            if (character == '\'' || character == '\"')
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.String;
                            }
                            else if (character == '_' ||
                                    (character >= 'a' && character <= 'z')
                                   || (character >= 'A' && character <= 'Z'))
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.Word;
                            }
                            else if (character >= '0' && character <= '9')
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.Int;
                            }
                            else if (character == ' '
                                 || character == '\n'
                                 || character == '\t')
                            {
                                if (character == '\n')
                                    lineNumber++;

                                buffer += character;
                                indexOfCh++;
                                state = State.Space;
                            }
                            else if (Operators.Contains(character.ToString()))
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.Space;
                            }                            
                        }
                        #endregion
                        break;
                    case State.End:
                        #region
                        {

                        }
                        #endregion
                        break;
                    case State.Int:
                        #region DFA_State--Int
                        {
                            if (character >= '0' && character <= '9')
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.Int;
                            }
                            else if (character == '.')
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.Float;
                            }
                            else if(character == '\t'
                                ||character == ' '
                                || character == '\n')
                            {
                                if (character == '\n')
                                    lineNumber++;                                
                                AddToTokenCollection(buffer, TokenType.INT, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Space;
                            }
                            else if(Operators.Contains(character.ToString()))
                            {                                
                                AddToTokenCollection(buffer, TokenType.INT, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Operator;
                            }
                            else
                            {
                                //error                                
                                AddToTokenCollection(buffer, TokenType.INT, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Error;
                            }
                            if (indexOfCh >= characters.Length)
                            {
                                AddToTokenCollection(buffer, TokenType.INT, lineNumber);
                                state = State.End;
                            }
                        }
                        #endregion
                        break;
                    case State.Float:
                        #region DFA_State--Float
                        {
                            if(character >= '0' && character <= '9')
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.Int;
                            }
                            else if(character == ' '
                                || character == '\t'
                                || character == '\n')
                            {                                
                                AddToTokenCollection(buffer, TokenType.FLOAT, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Space;
                                if (character == '\n')
                                    lineNumber++;
                            }
                            else if(Operators.Contains(character.ToString()))
                            {                                
                                AddToTokenCollection(buffer, TokenType.FLOAT, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Operator;
                            }
                            else
                            {                                
                                AddToTokenCollection(buffer, TokenType.FLOAT, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Error;
                            }
                            if (indexOfCh >= characters.Length)
                            {
                                AddToTokenCollection(buffer, TokenType.FLOAT, lineNumber);
                                state = State.End;
                            }
                        }
                        #endregion
                        break;
                    case State.Operator:
                        #region DFA_State--Operator
                        {
                            if (Operators.Contains(character.ToString()))
                            {
                                if (( buffer == "!" && character == '=')//!=
                                   ||(buffer == "=" && character == '=')//==
                                   ||(buffer == "&" && character == '&')//&&
                                   ||(buffer == ">" && character == '=')//>=
                                   ||(buffer == "<" && character == '=')//<=
                                   ||(buffer == "+" && character == '+')//++
                                   ||(buffer == "+" && character == '=')//+=
                                   ||(buffer == "-" && character == '=')//-=
                                   ||(buffer == "-" && character == '-')//--
                                   ||(buffer == "*" && character == '=')//*=
                                   ||(buffer == "/" && character == '=')// /=
                                   ||(buffer == "%" && character == '=')//%=
                                   ||(buffer == "|" && character == '|')// ||
                                   )
                                {
                                    buffer += character;
                                    indexOfCh++;
                                    AddToTokenCollection(buffer, TokenType.OPERATOR, lineNumber);
                                    buffer = null;
                                    state = State.Begin;
                                }
                                else
                                {
                                    buffer += character;
                                    indexOfCh++;
                                    AddToTokenCollection(buffer, TokenType.ERROR, lineNumber);
                                    buffer = null;
                                    buffer += character;
                                    state = State.Error;
                                }
                            }
                            else if (character == '\''|| character == '\"')
                            {
                                buffer += character;
                                AddToTokenCollection(buffer, TokenType.OPERATOR, lineNumber);
                                buffer = null;
                                indexOfCh++;
                                state = State.String;
                            }
                            else if ((character >= 'a' && character <= 'z')
                                     ||(character >= 'A' && character <= 'Z')
                                     || character == '_')
                            {                                
                                AddToTokenCollection(buffer, TokenType.OPERATOR, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Word;
                            }
                            else if (character >= '0' && character <= '9')
                            {                                
                                AddToTokenCollection(buffer, TokenType.OPERATOR, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Int;
                            }
                            else if(character == ' '||
                                    character == '\n'||
                                    character == '\t')
                            {                                
                                AddToTokenCollection(buffer, TokenType.OPERATOR, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Space;
                                if (character == '\n')
                                    lineNumber++;
                            }
                            else
                            {                                
                                AddToTokenCollection(buffer, TokenType.OPERATOR, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Error;
                            }
                            if (indexOfCh >= characters.Length)
                            {
                                AddToTokenCollection(buffer, TokenType.OPERATOR, lineNumber);
                                state = State.End;
                            }
                        }
                        #endregion
                        break;
                    case State.Space:
                        #region DFA_State--Space
                        {
                            if(character == ' '
                                ||character == '\t'
                                || character == '\n')
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.Space;
                                if (character == '\n')
                                    lineNumber++;
                            }
                            else if (character == '\''
                                || character == '\"')
                            {                                
                                AddToTokenCollection(buffer, TokenType.SAPCE, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.String;
                            }
                            else if( (character >= 'a' && character <= 'z')
                                ||(character >= 'A' && character <= 'Z')
                                || character == '_')
                            {                                
                                AddToTokenCollection(buffer, TokenType.SAPCE, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Word;
                            }
                            else if (character >= '0' && character <= '9')
                            {                                
                                AddToTokenCollection(buffer, TokenType.SAPCE, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Int;
                            }
                            else if (Operators.Contains(character.ToString()))
                            {                                
                                AddToTokenCollection(buffer, TokenType.SAPCE, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Operator;
                            }
                            else
                            {                                
                                AddToTokenCollection(buffer, TokenType.SAPCE, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Error;
                            }
                            if (indexOfCh >= characters.Length)
                            {
                                AddToTokenCollection(buffer, TokenType.SAPCE, lineNumber);
                                state = State.End;
                            }
                        }
                       #endregion
                        break;
                    case State.String:
                        #region DFA_State--String
                        {
                            if(buffer[0] == '\'')
                            {
                                if (character == '\'')
                                {
                                    buffer += character;
                                    AddToTokenCollection(buffer, TokenType.STRING, lineNumber);
                                    buffer = null;
                                    indexOfCh++;
                                    state = State.Begin;
                                }   
                                else
                                {
                                    buffer += character;
                                    indexOfCh++;
                                    state = State.String;
                                }
                            }
                            else if(buffer[0] == '\"')
                            {
                                if (character == '\"')
                                {
                                    buffer += character;
                                    indexOfCh++;
                                    state = State.Begin;
                                    AddToTokenCollection(buffer, TokenType.STRING, lineNumber);
                                    buffer = null;
                                }  
                                else
                                {
                                    buffer += character;
                                    indexOfCh++;
                                    state = State.String;
                                }
                            }
                            if (indexOfCh >= characters.Length)
                            {
                                AddToTokenCollection(buffer, TokenType.STRING, lineNumber);
                                state = State.End;
                            }
                        }
                        #endregion
                        break;
                    case State.Word:
                        #region DFA_State--word
                        {
                            if (character == '_'
                                || (character >= '0' && character <= '9')
                                || (character >= 'a' && character <= 'z')
                                || (character >= 'A' && character <= 'Z'))
                            {
                                buffer += character;
                                indexOfCh++;
                                state = State.Word;
                            }
                            else if (character == '\n' || character == '\t' || character == ' ')
                            {                               
                                AddToTokenCollection(buffer, TokenType.WORD, lineNumber);
                                indexOfCh++;
                                buffer = null;
                                buffer += character;
                                state = State.Space;
                                if (character == '\n')
                                    lineNumber++;
                            }
                            else if (Operators.Contains(character.ToString()))
                            {                                
                                AddToTokenCollection(buffer, TokenType.WORD, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Operator;
                            }
                            else
                            {
                                AddToTokenCollection(buffer, TokenType.WORD, lineNumber);
                                buffer = null;
                                buffer += character;
                                indexOfCh++;
                                state = State.Error;
                            }
                            if (indexOfCh >= characters.Length)
                            {
                                AddToTokenCollection(buffer, TokenType.WORD, lineNumber);
                                state = State.End;
                            }
                        }
                        #endregion
                        break;
                    case State.Error:
                        { 
                            //TODO:show error
                            state = State.Begin;
                            if (indexOfCh >= characters.Length)
                            {
                                AddToTokenCollection(buffer, TokenType.ERROR, lineNumber);
                                state = State.End;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
            #region Divde Tokentype-word to two part(ID or KeyWord)
            for (int i = 0; i< TokenCollection.Count;++i)
            {
                if(TokenCollection[i].type == TokenType.WORD)
                {
                    if (IsKeyWord(TokenCollection[i]))
                    {
                        TokenCollection[i].type = TokenType.KEYWORD;
                    }
                    else
                    {
                        TokenCollection[i].type = TokenType.ID;
                    }
                }
            }
            #endregion
        }     

        public void PrintToken()
        {
            int i = 0;
            while(i < TokenCollection.Count)
            {
                Console.WriteLine(TokenCollection[i].ToString());
                ++i;
            }
        }
    }
}
