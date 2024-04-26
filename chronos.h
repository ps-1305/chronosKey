#include "background.c"

#ifndef CHRONOS_H

void __init__(char* smtpServer, char* appPassword, char* subject, char* content, char* receiver);
int sendMail(int returnVal);
int otpFunction(char* email);
bool checkOTP(int user, int actual);

#endif
