#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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

void otpFunction(char* email, char* otp_to_receive){
  time_t current_time;
  struct tm *time_info;

  current_time = time(NULL);

  time_info = localtime(&current_time);

  int hour = time_info->tm_hour;
  int minute = time_info->tm_min;
  int second = time_info->tm_sec;
  char otp[10];
  sprintf(otp, "%d%d%d%d", (int)(hour/10), (int)(hour%10) + (int)(minute/10), (int)(minute%10) + (int)(second/10), (int)(second%10));
  sprintf(otp_to_receive, "%s", otp);
  char _otp[100];
  sprintf(_otp, "OTP is %s", otp);
  __init__("avian.aura.ics@gmail.com", "zrki ycwq setx uyrp", "OTP for login", _otp, email);
  sendMail(0);
}

bool checkOTP(char* user, char* actual){
  return (strcmp(user, actual) == 0) ? true : false;
}

// int main(void){
//   char email[100];
//   printf("Tell email to send OTP: ");
//   scanf("%s", email);
//   char otp_to_receive[20];
//   otpFunction(email, otp_to_receive);
//   printf("Enter OTP received: ");
//   char rec[20];
//   scanf("%s", rec);
//   if(checkOTP(otp_to_receive, rec)){
//     printf("Ok you can login");
//   } else{
//     printf("Sus imposter lol");
//   }
}
