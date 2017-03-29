using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_DFAToToken
{
    class Token
    {
        private string description;
        public string Description
        {
            get { return description; }
            set { description = value; }
        }

        private TokenType type;
        public TokenType Type
        {
            get { return type; }
            set { type = value; }
        }
        public Token(string content, TokenType type)
        {
            Description = content;
            Type = type;
        }
        public void SetType(TokenType type)
        {
            Type = type;
        }
        public override string ToString()
        {
            return Description + ' ' + type;
        } 
    }
}
