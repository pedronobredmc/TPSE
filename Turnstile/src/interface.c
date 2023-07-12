#include "interface.h"

void BemVindo_Interface(){
    uartPutString(UART0, "\n\r\n\r\n\r",8);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "*               Bem-vindo ao Sistema              *\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "\n\r\n\r\n\r",8);
}
void PessoaEntra_Interface(){
    uartPutString(UART0, "\n\r",4);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "*            Uma pessoa entrou na sala            *\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "***************************************************\n\r", 55);  
    uartPutString(UART0, "\n\r",4);
}
void PessoaSai_Interface(){
    uartPutString(UART0, "\n\r",4);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "*             Uma pessoa saiu da sala             *\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "\n\r",4);
}
void SalaQCheia_Interface_saiu(){
    uartPutString(UART0, "\n\r",4);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "*         Atenção, a sala esta quase cheia        *\n\r", 55);
    uartPutString(UART0, "*             Uma pessoa saiu da sala             *\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "\n\r",4);
}   
void SalaCheia_Interface(){
    uartPutString(UART0, "\n\r",4);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "*            Atenção!! A sala esta cheia          *\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "\n\r",4);
}
void SalaLimpa_Interface(){
    uartPutString(UART0, "\n\r",4);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "*                 A sala esta vazia               *\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "\n\r",4);
}

void SalaQCheia_Interface_entrou(){
    uartPutString(UART0, "\n\r",4);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "*         Atenção, a sala esta quase cheia        *\n\r", 55);
    uartPutString(UART0, "*             Uma pessoa entrou na sala           *\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "\n\r",4);
}

void Sistema_desligado(){
    uartPutString(UART0, "\n\r",4);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "*                 Sistema desligado               *\n\r", 55);
    uartPutString(UART0, "*                                                 *\n\r", 55);
    uartPutString(UART0, "***************************************************\n\r", 55);
    uartPutString(UART0, "\n\r",4);
}