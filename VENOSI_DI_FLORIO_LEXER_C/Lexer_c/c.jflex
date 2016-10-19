
import java_cup.runtime.*;
import java.util.Set;

%%


%cup
%line
%column
%unicode
%class CLexer

/*
%eofval{
    return newSym(sym.EOF);
%eofval}
*/

%{
	
    StringBuffer buff = new StringBuffer();

 	int countNum = 0;
	int countID = 0;
	int countString = 0;
	

    public int curr_line(){
        return yyline;
    }
     public int curr_col(){
        return yycolumn;
    }
	
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

 private long parseNum(int start, int end, int radix) {
    long result = 0;
    long digit;

    for (int i = start; i < end; i++) {
      digit  = Character.digit(yycharat(i),radix);
      result*= radix;
      result+= digit;
    }

    return result;
  }
	
%}


%state COMMENT, LINE_COMMENT, STRING

OctDigit        = [0-7]
HexDigit        = [0-9a-fA-F]
letter          = [A-Za-z]
digit           = [0-9]
alphanumeric    = {letter}|{digit}
other_id_char   = [_]
HexLiteral 	= 0 [xX] 0* {HexDigit} {1,8}
OctLiteral 	= 0+ [1-3]? {OctDigit} {1,15}
integer         = {digit}*
real            = {integer}\.{integer}
char            = '.'
identifier      = ({other_id_char}|{letter})({alphanumeric}|{other_id_char})*
nonrightbrace   = [^}]
slash		= \/
newline		= \\n
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
  "case"                         { return newSym(sym.CASE); }
  "char"                         { return newSym(sym.CHAR_TYPE); }
  "const"                        { return newSym(sym.CONST); }
  "continue"                     { return newSym(sym.CONTINUE); }
  "do"                           { return newSym(sym.DO); }
  "double"                       { return newSym(sym.DOUBLE_TYPE); }
  "else"                         { return newSym(sym.ELSE); }
  "extern"                       { return newSym(sym.EXTERN); }
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
  "typedef"                      { return newSym(sym.TYPEDEF); }
  "volatile"                     { return newSym(sym.VOLATILE); }
  "enum"			 { return newSym(sym.ENUM); }
  "register"			 { return newSym(sym.REGISTER); }
  "sizeof"			 { return newSym(sym.SIZEOF); }
  "signed"			 { return newSym(sym.SIGNED); }
  "unsigned"                     { return newSym(sym.UNSIGNED); }
  "struct"		         { return newSym(sym.STRUCT); }
 
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
  "->"			         { return newSym(sym.PTR_OP); }
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
  "..."		                 { return newSym(sym.ELLIPSIS); }
  
{identifier}    { Tables.symTable.put(countID, new String(yytext()) ); int c = countID; countID++; return newSym(sym.ID,c); }
{HexLiteral}	{ Tables.numTable.put(countNum, new String("" +  parseNum(2, yylength(), 16)) );int c = countNum; countNum++; return newSym(sym.HEX_CONSTANT,c); }
{OctLiteral} 	{ Tables.numTable.put(countNum, new String("" +  parseNum(0, yylength(), 8)) );int c = countNum; countNum++; return newSym(sym.OCT_CONSTANT,c); }
{integer}       { Tables.numTable.put(countNum, new String(yytext()) );int c = countNum; countNum++; return newSym(sym.INT_CONSTANT,c); }
{real}          { Tables.numTable.put(countNum,new String( yytext())) ;int c = countNum; countNum++; return newSym(sym.REAL_CONSTANT,c); }
{char}          { Tables.numTable.put(countNum, new String( "" + yytext().charAt(1)));int c = countNum; countNum++; return newSym(sym.CHAR_CONSTANT,c); }
{whitespace}    { /* Ignore whitespace. */ }

\"           	      { buff.setLength(0); yybegin(STRING); }

{comment_line}        { System.out.print("comment line\n"); yybegin(LINE_COMMENT); }


"/*" 		      { yybegin(COMMENT); System.out.print("comment_body\n"); }

{ILLEGAL} 	      { return newSym(sym.ERROR, "Illegal char, '" + yytext() +"' line: " + yyline + ", column: " + yycolumn); }
.                     { return newSym(sym.ERROR, "Illegal char, '" + yytext() +"' line: " + yyline + ", column: " + yycolumn); }


} /* fine stato YYINITIAL */




<COMMENT> "/*"			{ }
<COMMENT> "*/"			{ yybegin(YYINITIAL); }
<COMMENT>[^*/]* 		{/* Eat non-comment delimiters */}
<COMMENT>[*/]  			{ /* Eat a / or * if it doesn't match comment sequence */}
<COMMENT>"//".*                 { /* // comments to end of line */}
<COMMENT> <<EOF>> 		{yybegin(YYINITIAL);return newSym(sym.ERROR, "EOF in comment");}




<LINE_COMMENT>.*        {}
<LINE_COMMENT>\r        {}
<LINE_COMMENT>\u000A    { yybegin(YYINITIAL); }




<STRING>\"              { yybegin(YYINITIAL);Tables.stringTable.put(countString,new String( buff.toString()));int c = countString; countString++; System.out.println("buffer: " + buff); return newSym(sym.STRING,c); }
<STRING>\\n             { buff.append('\n'); }
<STRING>\\t             { buff.append('\t'); }
<STRING>\\b             { buff.append('\b'); }
<STRING>\\f             { buff.append('\f'); }
<STRING>\\\'            { buff.append('\''); }
<STRING>\\\"            { buff.append('\"'); }
<STRING>\\              { buff.append('\\'); }
<STRING>\u000A          { return newSym(sym.ERROR, "Unterminated string constant"); }
<STRING> \\[ ]*\u000A   {}
/*error*/
<STRING>\\.             {return newSym(sym.ERROR,"Illegal escape sequence \""+yytext()+"\"");}
<STRING>.               { buff.append(yytext()); }
<STRING> <<EOF>>        {yybegin(YYINITIAL);return newSym(sym.ERROR, "Unterminated string constant");}

