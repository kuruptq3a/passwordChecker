#include <stdio.h>
#include <string.h>
#include <ctype.h>
int specialCharactersPass = 0;
int numbersInPasswordPass = 0;
int passwordLengthPass = 0;
int upperCharactersPass = 0;
int passwordSetupCompleted = 0;
void CountSpecialCharacters(char specChar[]){
    int count = 0;
    char specialCharacterList[] = "!#$%^&*";
    for(int i = 0; i < strlen(specChar); i++){
        for(int j = 0; j < strlen(specialCharacterList); j++){
            if(specChar[i] == specialCharacterList[j]){
                count++;
            }
        }
    }
    if(count < 2){
        printf("\nYour password has insufficient special characters");
    }else{
        //printf("\nYour password has sufficuent special characters");
        specialCharactersPass = 1;
    }
}

void CountNumbersInPassword(char numbers[]){
    int count = 0;
    char numList[] = {'1','2','3','4','5','6','7','8','9','9'};
    for(int i = 0; i < strlen(numbers); i++){
        for(int j = 0; j < strlen(numList); j++){
            if(numbers[i] == numList[j]){
                count++;
            }
        }
    }
    if(count < 2){
        printf("\nInsufficient numbers in your password");
    }else{
        //printf("\nYour password has sufficient numbers in it.");
        numbersInPasswordPass = 1;
    }

}

void checkPassWordLength(char pwLength[]){
    if(strlen(pwLength) >= 7 && strlen(pwLength) <=20){
        //printf("\nYour password length is acceptable");
        passwordLengthPass = 1;
    }else{
        //printf("\nYour password must be between 7 and 20 characters,");
    }
}

void SetupComplete(){
    int completed_checkpoint = 0;
    int steps = 3;
    printf("\nChecking if your password is setup.....");
    if(specialCharactersPass == 1){
        completed_checkpoint++;
        steps--;
        printf("\nSpecial Characters confirmed.");
    }else{
        printf("\nInsufficient special characters.");
    }
    if(numbersInPasswordPass == 1){
        printf("\nNumeric check completed.");
        completed_checkpoint++;
        steps--;
    }else{
        printf("\nInsufficient numbers in your password.");
    }
    if(passwordLengthPass ==1){
        printf("\nPassword length check completed.");
        completed_checkpoint++;
        steps--;
    }else{
        printf("\nPassword length is incorrect.");
        printf("\nYour password must be within 7 to 20 characters.");
    }
    
    if(steps == 3 && completed_checkpoint != 3){
        printf("\nYour password could not be completed.");
    }else{
        printf("\nYour password has been setup.");
        passwordSetupCompleted = 1;
    }

}

int main() {
    char password[20];
    printf("\nPlease enter your desired password");
    printf("\nYour password must consist of 2 number, 2 special characters");
    printf("\nand it must be between 7 to 20 characters");
    scanf("%s",password);
    CountSpecialCharacters(password);
    CountNumbersInPassword(password);
    checkPassWordLength(password);
    SetupComplete();

    
}
