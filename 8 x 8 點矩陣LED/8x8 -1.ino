int l[6]={8,9,10,11,12,13};
int c[6]={0,1,2,3,4,5};
int a[6][6]={{0,0,0,0,0,0},
             {0,1,1,1,1,0},
             {0,1,0,0,1,0},
             {0,1,0,0,1,0},
             {0,1,1,1,1,0},
             {0,0,0,0,0,0}};
void setup() {
  for(int i=0;i<6;i++){
    pinMode(l[i],OUTPUT);
    pinMode(c[i],OUTPUT);
    digitalWrite(l[i],LOW);
    digitalWrite(c[i],HIGH);
  }
}

void loop() {
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      if(a[i][j]==1){
        digitalWrite(l[i],HIGH);
        digitalWrite(c[j],LOW);
        delay(1);
        digitalWrite(l[i],LOW);
        digitalWrite(c[j],HIGH);
        
      }
    }
  }
}
