using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter.Scanner
{
    enum TokenType
    {
        WORD,
        KEYWORD,
        ID,
        SAPCE,
        INT, 
        OPERATOR, 
        FLOAT, 
        STRING, 
        ERROR, 
        DEFULT
    }
}
