
import java_cup.runtime.*;


%%


%cup
%line
%column
%unicode
%class PascalLexer
%debug

%eofval{
    switch(zzLexicalState) {
		case YYINITIAL:
		break;
		case COMMENT:
		yybegin(YYINITIAL);
		return newSym(sym.ERROR, "EOF in comment");
		case LINE_COMMENT:
		break;
		case STRING:
		yybegin(YYINITIAL);
		return newSym(sym.ERROR, "EOF in string constant");
	}
    return newSym(sym.EOF);
%eofval}


%{
	// Max size of string constants
    StringBuffer buff = new StringBuffer();
 	
	int comment_nesting = 0;

	
/**
 * Return a new Symbol with the given token id, and with the current line and
 * column numbers.
 */
Symbol newSym(int tokenId) {
    return new Symbol(tokenId, yyline, yycolumn);
}

/**
 * Return a new Symbol with the given token id, the current line and column
 * numbers, and the given token value.  The value is used for tokens such as
 * identifiers and numbers.
 */
Symbol newSym(int tokenId, Object value) {
    return new Symbol(tokenId, yyline, yycolumn, value);
}
	
%}


%state COMMENT, LINE_COMMENT, STRING , NUMERIC


letter          = [A-Za-z]
digit           = [0-9]
alphanumeric    = {letter}|{digit}
other_id_char   = [_]
memID			= &{identifier}
pointerID		= (\*[\*]?{identifier})
integer_hex 	= (0[Xx][0-9A-Fa-f]+)
integer_oct		= 0[0-7]*
integer         = {digit}*
real            = {integer}\.{integer}
char            = '.'
identifier      = ({other_id_char}|{letter})({alphanumeric}|{other_id_char})*
nonrightbrace   = [^}]
slash			= \/
newline			= \\n
comment_line    = {slash}{slash}+
whitespace      = [ \n\t]
ILLEGAL	        = [^\n \t\f\x0b\rA-Za-z0-9+/\-*=<.~,;:()@\}\{\"_]


%%
/**
 * LEXICAL RULES:
 */

<YYINITIAL> {

  /* keywords */
 
 

  "break"                        { return newSym(sym.BREAK); }
  "byte"                         { return newSym(sym.BYTE); }
  "case"                         { return newSym(sym.CASE); }
  "catch"                        { return newSym(sym.CATCH); }
  "char"                         { return newSym(sym.CHAR_TYPE); }
  "const"                        { return newSym(sym.CONST); }
  "continue"                     { return newSym(sym.CONTINUE); }
  "do"                           { return newSym(sym.DO); }
  "double"                       { return newSym(sym.DOUBLE_TYPE); }
  "else"                         { return newSym(sym.ELSE); }
  "extends"                      { return newSym(sym.EXTENDS); }
  "final"                        { return newSym(sym.FINAL); }
  "finally"                      { return newSym(sym.FINALLY); }
  "float"                        { return newSym(sym.FLOAT_TYPE); }
  "for"                          { return newSym(sym.FOR); }
  "default"                      { return newSym(sym.DEFAULT); }
  "int"                          { return newSym(sym.INT_TYPE); }
  "long"                         { return newSym(sym.LONG_TYPE); }
  "goto"                         { return newSym(sym.GOTO); }
  "if"                           { return newSym(sym.IF); } 
  "short"                        { return newSym(sym.SHORT_TYPE); }
  "switch"                       { return newSym(sym.SWITCH); }
  "return"                       { return newSym(sym.RETURN); }
  "void"                         { return newSym(sym.VOID); }
  "static"                       { return newSym(sym.STATIC); }
  "while"                        { return newSym(sym.WHILE); }
  "this"                         { return newSym(sym.THIS); }
  "volatile"                     { return newSym(sym.VOLATILE); }
  
  
 
  /* null literal */
  "NULL"                         { return newSym(sym.NULL_LITERAL); }
  
  
  /* separators */
  "("                            { return newSym(sym.LPAREN); }
  ")"                            { return newSym(sym.RPAREN); }
  ("{"|"<%")                     { return newSym(sym.LBRACE); }
  ("}"|"%>")                     { return newSym(sym.RBRACE); }
  ("["|"<:")                     { return newSym(sym.LBRACK); }
  ("]"|":>")                     { return newSym(sym.RBRACK); }
  ";"                            { return newSym(sym.SEMICOLON); }
  ","                            { return newSym(sym.COMMA); }
  "."                            { return newSym(sym.DOT); }

  /* operators */
  "="                            { return newSym(sym.EQ); }
  ">"                            { return newSym(sym.GT); }
  "<"                            { return newSym(sym.LT); }
  "!"                            { return newSym(sym.NOT); }
  "~"                            { return newSym(sym.COMP); }
  "?"                            { return newSym(sym.QUESTION); }
  ":"                            { return newSym(sym.COLON); }
  "=="                           { return newSym(sym.EQEQ); }
  "<="                           { return newSym(sym.LTEQ); }
  ">="                           { return newSym(sym.GTEQ); }
  "!="                           { return newSym(sym.NOTEQ); }
  "&&"                           { return newSym(sym.ANDAND); }
  "||"                           { return newSym(sym.OROR); }
  "++"                           { return newSym(sym.PLUSPLUS); }
  "--"                           { return newSym(sym.MINUSMINUS); }
  "+"                            { return newSym(sym.PLUS); }
  "-"                            { return newSym(sym.MINUS); }
  "*"                            { return newSym(sym.MULT); }
  "/"                            { return newSym(sym.DIV); }
  "&"                            { return newSym(sym.AND); }
  "|"                            { return newSym(sym.OR); }
  "^"                            { return newSym(sym.XOR); }
  "%"                            { return newSym(sym.MOD); }
  "<<"                           { return newSym(sym.LSHIFT); }
  ">>"                           { return newSym(sym.RSHIFT); }
  ">>>"                          { return newSym(sym.URSHIFT); }
  "+="                           { return newSym(sym.PLUSEQ); }
  "-="                           { return newSym(sym.MINUSEQ); }
  "*="                           { return newSym(sym.MULTEQ); }
  "/="                           { return newSym(sym.DIVEQ); }
  "&="                           { return newSym(sym.ANDEQ); }
  "|="                           { return newSym(sym.OREQ); }
  "^="                           { return newSym(sym.XOREQ); }
  "%="                           { return newSym(sym.MODEQ); }
  "<<="                          { return newSym(sym.LSHIFTEQ); }
  ">>="                          { return newSym(sym.RSHIFTEQ); }
  ">>>="                         { return newSym(sym.URSHIFTEQ); }

{identifier}    { return newSym(sym.ID, yytext()); }
{pointerID} 	{ return newSym(sym.POINTER_ID, yytext()); }
{memID}			{ return newSym(sym.MEM_ID, yytext()); }
{integer_hex}	{ return newSym(sym.CONSTANT, new Integer(yytext())); }
{integer_oct} 	{ return newSym(sym.CONSTANT, new Integer(yytext())); }
{integer}       { return newSym(sym.CONSTANT, new Integer(yytext())); }
{real}          { return newSym(sym.CONSTANT, new Double(yytext())); }
{char}          { return newSym(sym.CONSTANT, new Character(yytext().charAt(1))); }
{whitespace}    { /* Ignore whitespace. */ }

\"           		  { buff.setLength(0); yybegin(STRING); }

{comment_line}        { System.out.print("comment line: "); yybegin(LINE_COMMENT); }


"/*"  		{ yybegin(COMMENT); System.out.print("comment: ");  }

{ILLEGAL} 	{ return newSym(sym.ERROR, yytext()); }
.           { System.out.println("Illegal char, '" + yytext() +"' line: " + yyline + ", column: " + yychar); }

}

<COMMENT> "/*"			{  comment_nesting++; System.out.println("comment_nesting: " + comment_nesting);  }
<COMMENT> "*/"			{ if (comment_nesting == 0) yybegin(YYINITIAL);comment_nesting--;  }
<COMMENT> [^\/\*]+		{}
<COMMENT> "/"			{}
<COMMENT> "*"			{}
<COMMENT> {whitespace}  { /* Ignore whitespace. */ }
<COMMENT> <<EOF>> 			{yybegin(YYINITIAL);return newSym(sym.ERROR, "EOF in comment");}

<LINE_COMMENT>.*        {System.out.print(yytext() + " ");}
<LINE_COMMENT>\r        {}
<LINE_COMMENT>\n        { yybegin(YYINITIAL); }

<STRING>\"              { yybegin(YYINITIAL); System.out.println("buffer: " + buff); return newSym(sym.STRING,buff); }
<STRING>\n              { yybegin(YYINITIAL);  return newSym(sym.ERROR, "Unterminated string constant"); }


<STRING> \\[ ]*\n       {}

<STRING>\\n             { buff.append('\n'); }

<STRING>\\t             { buff.append('\t'); }

<STRING>\\b             { buff.append('\b'); }

<STRING>\\f             { buff.append('\f'); }

<STRING>.               { buff.append(yytext()); }


