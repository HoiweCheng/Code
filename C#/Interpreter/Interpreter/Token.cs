using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Scanner
{    
    class Token
    {      
        public string Description;
        public TokenType type;
        public int lineNumber;
        public Token()
        {
            Description = null;
            type = TokenType.DEFULT;
            lineNumber = 1;
        }
        public Token(string Content, int linenumber = 1, TokenType Type = TokenType.DEFULT)
        {
            type = Type;
            Description = Content;
            lineNumber = linenumber;
        }
        public void TokenSetType(TokenType Type = TokenType.DEFULT)
        {            
            type = Type;
        }
        public override string ToString()
        {
            return this.Description +"  " + this.type.ToString();
        }

    }
}
