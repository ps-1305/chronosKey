#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE* gmailExecutable;

void __init__(char* smtpServer, char* appPassword, char* subject, char* content, char* receiver){
  gmailExecutable = fopen("sendMail.py","w");
  fprintf(gmailExecutable, "import smtplib\n");
  fprintf(gmailExecutable, "senderMail = \"%s\"\n", smtpServer); 
  fprintf(gmailExecutable, "appPassword = \"%s\"\n", appPassword); 
  fprintf(gmailExecutable, "gmailSubject = \"%s\"\n", subject); 
  fprintf(gmailExecutable, "gmailContent = \"%s\"\n", content); 
  fprintf(gmailExecutable, "gmailReceiver = \"%s\"\n", receiver); 
  fprintf(gmailExecutable, "gmail = gmailReceiver.split()\n"); 
  fprintf(gmailExecutable, "server = smtplib.SMTP('smtp.gmail.com', 587)\n"); 
  fprintf(gmailExecutable, "server.starttls()\n"); 
  fprintf(gmailExecutable, "server.login(senderMail, appPassword)\n"); 
  fprintf(gmailExecutable, "message = f'''Subject: {gmailSubject}\n\n{gmailContent}'''\n"); 
  fprintf(gmailExecutable, "server.sendmail(senderMail, gmail, message)\n"); 
  fclose(gmailExecutable);
}

int sendMail(int returnVal){
  system("python3 sendMail.py");
  switch(returnVal){
  case 0: return 0; break;
  case -1: return -1; break;  
  default: return 0; break;
  }
}

int otpFunction(char* email){
  int otp = rand() % (99999 - 10000 + 1) + 10000;
  char _otp[100];
  sprintf(_otp, "OTP is %d", otp);
  __init__("avian.aura.ics@gmail.com", "zrki ycwq setx uyrp", "OTP for login", _otp, email);
  sendMail(0);
  return otp;
}

bool checkOTP(int user, int actual){
  return (user==actual) ? true : false;
}

// int main(void){
//   char email[100];
//   printf("Tell email to send OTP: ");
//   scanf("%s", email);
//   int otp_to_receive = otpFunction(email);
//   printf("Enter OTP received: ");
//   int rec;
//   scanf("%d", &rec);
//   if(checkOTP(otp_to_receive, rec)){
//     printf("Ok you can login");
//   } else{
//     printf("Sus imposter lol");
//   }
}
