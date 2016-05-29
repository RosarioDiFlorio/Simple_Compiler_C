
import java.io.*;
import java.util.HashMap;

import java_cup.runtime.*;

public class CLexerTest {

/* usato solo per poter stampare la coppia <Nome Token, Attributo> */
	private static final Integer[] TOKEN_IDS = new Integer[] { 
	0,
 	1,
	2,
    3,
    4,  
    5,
    6,
    7,
    8,
    9,
   	10,
  	11,
  	12,
   	13,
  	14,
   	15,
   	16,
   	17,
  	18,
   	19,
   	20, 
   	21,
   	22,
  	 23,
   	24,
   	25,
   	26,
   	27,
   	28,
   	29,
  	30,
  	31,
  	32,
  	33,
   	34,
   	35,
   	36,
  	37,
  	38,
  
 
  	39,
  	40,
  	41,
  	42,
  	43,
 	44,
   	45,
   	46,
 	47,
  	48,
 	49,
  	50,
 	51,
  	52,
	53,
	54,
 	55,
 	56,
 	57,
  	58,
  	59,
  	60,
 	61,
	62,
 	63,
 	64,
	65,
  	66,
  	67,
 	68,
 	69,
 	70,
 	71,
 	72,
 	73,
 	74,
  	75,
 	76,

	80,
	81,
	82,
	84,
	85,
	86,
	87,
	88


	 };

	private static final String[] TOKEN_NAMES = new String[] { 
 "EOF",
  "BREAK",
  "BYTE",
  "CASE",
 "CATCH", 
  "CHAR_TYPE",
  "CONST",
  "CONTINUE",
  "DO",
  "DOUBLE_TYPE",
  "ELSE",
  "EXTERN",
  "FINAL",
  "FINALLY",
  "FLOAT_TYPE",
  "FOR",
  "DEFAULT",
  "INT_TYPE",
  "LONG_TYPE",
  "GOTO",
  "IF",
  "SHORT_TYPE",
  "SWITCH",
  "RETURN",
  "VOID",
  "STATIC",
  "WHILE",
  "TYPEDEF",
  "VOLATILE",
  "NULL_LITERAL",
 "LPAREN",
 "RPAREN",
 "LBRACE",
 "RBRACE",
  "LBRACK",
  "RBRACK",
  "SEMICOLON",
  "COMMA",
 "DOT",
  
 
 "EQ",
 "GT",
 "LT",
 "NOT",
 "COMP",
 "QUESTION",
  "COLON",
  "EQEQ",
 "LTEQ",
 "GTEQ",
"NOTEQ",
  "ANDAND",
  "OROR",
  "PLUSPLUS",
"MINUSMINUS",
 "PLUS",
 "MINUS",
 "MULT",
 "DIV",
  "AND",
  "OR",
  "XOR",
 "MOD",
"LSHIFT",
 "RSHIFT",
 "URSHIFT",
"PLUSEQ",
  "MINUSEQ",
  "MULTEQ",
 "DIVEQ",
 "ANDEQ",
 "OREQ",
 "XOREQ",
 "MODEQ",
  "LSHIFTEQ",
 "RSHIFTEQ",
  "URSHIFTEQ",
 "ID",

"CONSTANT",
"ERROR",
"STRING",
"MEM_ID",
"ENUM",
"REGISTER",
"SIZEOF",
"SIGNED" };

	public static void main(String[] args) {
		HashMap<Integer, String> tokenNames = new HashMap<Integer, String>();
		for (int i = 0; i < TOKEN_IDS.length; i++)
			tokenNames.put(TOKEN_IDS[i], TOKEN_NAMES[i]);

		Symbol sym;
		try {
			CLexer lexer = new CLexer(new FileReader(args[0]));

			for (sym = lexer.next_token(); sym.sym != 0; sym = lexer.next_token()) {
        /* stampa della coppia <Nome Token, Attributo> e posizione di linea e colonna */
      	System.out.println("<" + tokenNames.get(sym.sym) + (sym.value == null ? "" : "," + sym.value)
						+ ">  at line " + sym.left + ", column " + sym.right);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
