import java.io.*;
import java_cup.runtime.*;
import java.util.*;

%%

%class Lexer
%cup
%line
%char
%column
%implements sym

%{

  
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
    
  //    static TreeSet typeset = new TreeSet();
    
    private int typecheck(String s){

	if (Parser.lookupType(s.trim())) {
	    return TYPE_NAME;
	}

	else {
	    return IDENTIFIER;
	}
	
    }
    
%}

%eofval{
      return newSym(sym.EOF);
%eofval}

D		=	[0-9]
L		=	[a-zA-Z_]
H		=	[a-fA-F0-9]
E		=	[Ee][+-]?{D}+
FS		=	(f|F|l|L)
IS		=	(u|U|l|L)*
TC              =       "/*" [^*] ~"*/" | "/*" "*"+ "/"
EC              =       "//" [^\r\n]* {new_line}    
new_line        =       \r|\n|\r\n
white_space     =       {new_line} | [ \t\f]

%%
{EC}                    { }
{TC}                    { }

"auto"			{ return newSym(AUTO,yytext()); }
"break"			{ return newSym(BREAK,yytext()); }
"case"			{ return newSym(CASE,yytext()); }
"char"			{ return newSym(CHAR,yytext()); }
"const"			{ return newSym(CONST,yytext()); }
"continue"		{ return newSym(CONTINUE,yytext()); }
"default"		{ return newSym(DEFAULT,yytext()); }
"do"			{ return newSym(DO,yytext()); }
"double"		{ return newSym(DOUBLE,yytext()); }
"else"			{ return newSym(ELSE,yytext()); }
"enum"			{ return newSym(ENUM,yytext()); }
"extern"		{ return newSym(EXTERN,yytext()); }
"float"			{ return newSym(FLOAT,yytext()); }
"for"			{ return newSym(FOR,yytext()); }
"goto"			{ return newSym(GOTO,yytext()); }
"if"			{ return newSym(IF,yytext()); }
"int"			{ return newSym(INT,yytext()); }
"long"			{ return newSym(LONG,yytext()); }
"register"		{ return newSym(REGISTER,yytext()); }
"return"		{ return newSym(RETURN,yytext()); }
"short"			{ return newSym(SHORT,yytext()); }
"signed"		{ return newSym(SIGNED,yytext()); }
"sizeof"		{ return newSym(SIZEOF,yytext()); }
"static"		{ return newSym(STATIC,yytext()); }
"struct"		{ return newSym(STRUCT,yytext()); }
"switch"		{ return newSym(SWITCH,yytext()); }
"typedef"		{ return newSym(TYPEDEF,yytext()); }
"union"			{ return newSym(UNION,yytext()); }
"unsigned"		{ return newSym(UNSIGNED,yytext()); }
"void"			{ return newSym(VOID,yytext()); }
"volatile"		{ return newSym(VOLATILE,yytext()); }
"while"			{ return newSym(WHILE,yytext()); }

{L}({L}|{D})*		{ return newSym(typecheck(yytext()), yytext()); }

0[xX]{H}+{IS}?		{ return newSym(CONSTANT,yytext()); }
0{D}+{IS}?		{ return newSym(CONSTANT,yytext()); }
{D}+{IS}?		{ return newSym(CONSTANT,yytext()); }
L?'(\\.|[^\\'])+'	{ return newSym(CONSTANT,yytext()); }

{D}+{E}{FS}?		{ return newSym(CONSTANT,yytext()); }
{D}*"."{D}+({E})?{FS}?	{ return newSym(CONSTANT,yytext()); }
{D}+"."{D}*({E})?{FS}?	{ return newSym(CONSTANT,yytext()); }

L?\"(\\.|[^\\\"])*\"	{ return newSym(STRING_LITERAL,yytext()); }

"..."			{ return newSym(ELLIPSIS); }
">>="			{ return newSym(RIGHT_ASSIGN); }
"<<="			{ return newSym(LEFT_ASSIGN); }
"+="			{ return newSym(ADD_ASSIGN); }
"-="			{ return newSym(SUB_ASSIGN); }
"*="			{ return newSym(MUL_ASSIGN); }
"/="			{ return newSym(DIV_ASSIGN); }
"%="			{ return newSym(MOD_ASSIGN); }
"&="			{ return newSym(AND_ASSIGN); }
"^="			{ return newSym(XOR_ASSIGN); }
"|="			{ return newSym(OR_ASSIGN); }
">>"			{ return newSym(RIGHT_OP); }
"<<"			{ return newSym(LEFT_OP); }
"++"			{ return newSym(INC_OP,"++"); }
"--"			{ return newSym(DEC_OP,"--"); }
"->"			{ return newSym(PTR_OP); }
"&&"			{ return newSym(AND_OP,"&&"); }
"||"			{ return newSym(OR_OP,"||"); }
"<="			{ return newSym(LE_OP,"<="); }
">="			{ return newSym(GE_OP,">="); }
"=="			{ return newSym(EQ_OP,"=="); }
"!="			{ return newSym(NE_OP,"!="); }
";"			{ return newSym(SEMI); }
("{"|"<%")		{ return newSym(CURLYL); }
("}"|"%>")		{ return newSym(CURLYR); }
","			{ return newSym(COMMA); }
":"			{ return newSym(COLON); }
"="			{ return newSym(ASSIGN); }
"("			{ return newSym(PARAL); }
")"			{ return newSym(PARAR); }
("["|"<:")		{ return newSym(SQUAREDL); }
("]"|":>")		{ return newSym(SQUAREDR); }
"."			{ return newSym(POINT); }
"&"			{ return newSym(ADRESS); }
"!"			{ return newSym(NOT,"!"); }
"~"			{ return newSym(TILDE); }
"-"			{ return newSym(MINUS); }
"+"			{ return newSym(PLUS,"+"); }
"*"			{ return newSym(MUL,"*"); }
"/"			{ return newSym(DIVIDE,"/"); }
"%"			{ return newSym(MODULUS,"%"); }
"<"			{ return newSym(LESS,"<"); }
">"			{ return newSym(GREATER,">"); }
"^"			{ return newSym(XOR); }
"|"			{ return newSym(OR); }
"?"			{ return newSym(COND); }

{white_space}		{ /* ignore bad characters */ }
.|\n			{ System.err.println("Fehler: unbekanntes Zeichen:"+yytext()+" "+(yyline+1)+"/"+(yycolumn+1)); }

