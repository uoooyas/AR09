/*
 예제 6.6
 소리 입력
 */

// A0번 핀에서 사운드 입력을 받는다
char soundInputPin = 0;

// 그래프 바 LED 출력핀을 level 변수에 저장
char ledLevel[8] = {2, 3, 4, 5, 6, 7, 8, 9};

const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
const int led5 = 5;
const int led6 = 6;
const int led7 = 7;
const int led8 = 8;
const int led9 = 9;


void setup() {
  pinMode(led2, OUTPUT);
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
  pinMode(led3, OUTPUT);
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
  pinMode(led4, OUTPUT);
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
  pinMode(led5, OUTPUT);
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
  pinMode(led6, OUTPUT);
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
  pinMode(led7, OUTPUT);
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
  pinMode(led8, OUTPUT);
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
  pinMode(led9, OUTPUT);
// 시리얼 통신을 설정한다.  
  Serial.begin(9600);
  // 그래프 바 LED 핀을 출력으로 설정  
  for(int i=0 ; i<=7 ; i++){
    pinMode(ledLevel[i],OUTPUT);
  }
}

void loop(){
 
  // A0번 핀에서 사운드 입력을 받는다
  int soundInput = analogRead(soundInputPin);
  // 노이즈부분을 제외한 50~900의 범위로 입력받은 사운드 크기를 
  // 0~7단계로 변경한다.
  int soundLevel = map(soundInput, 50, 900, 0, 7);


  // 전체 LED를 소등한다.
  for(int i = 0; i <=7; i++){
    digitalWrite(ledLevel[i], LOW);
  }

  // 0~7 단계 중 입력보다 작은 레벨의 LED는 점등한다.
  for(int i = 0; i <= soundLevel; i++){
  digitalWrite(ledLevel[i], HIGH);
  }
  Serial.print("Sound input : ");
  Serial.print(soundInput);
  Serial.print(", ");
  Serial.print("sound level : ");
  Serial.println(soundLevel); 

}
