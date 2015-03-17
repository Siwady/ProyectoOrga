#include "VGA.h";
#define LineAmount 6
int y =0;
int x=0;
int object=0;
unsigned char small_ball[] = { 
    RED, RED, RED, RED, RED, WHITE , 
    RED, RED, RED, RED, RED, WHITE , 
    RED, RED, RED, RED, RED, WHITE , 
    RED, RED, RED, RED, RED, WHITE , 
    RED, RED, RED, RED, RED, WHITE , 
    WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
};

struct Line{
  int y1;
  int x1;
  int x2;
  int y2;
};
unsigned char Car[] = { 
    BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, RED, BLACK, BLACK, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK,CYAN, CYAN, YELLOW, YELLOW, CYAN, RED, RED, RED, RED, CYAN, YELLOW, YELLOW, CYAN, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, BLUE, BLUE, BLUE, BLUE, RED, RED, RED, RED, BLUE, BLUE, BLUE, BLUE, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, BLUE, BLUE, BLUE, RED, RED, RED, RED, RED, RED, BLUE, BLUE, BLUE, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, CYAN, CYAN, CYAN, RED, RED, RED, RED, RED, RED, CYAN, CYAN, CYAN, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, RED, RED, RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, RED, RED, RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, RED, RED, RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK, WHITE, WHITE, BLACK, RED, RED, RED, RED, RED, RED, BLACK, WHITE, WHITE, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, RED, RED, WHITE, WHITE, RED, RED, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, RED, RED, WHITE, WHITE, RED, RED, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, RED, RED, WHITE, WHITE, RED, RED, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, RED, RED, WHITE, WHITE, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, RED, RED, WHITE, WHITE, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, RED, RED, WHITE, WHITE, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, RED, RED, WHITE, WHITE, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, RED, RED, BLACK, BLACK, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, RED, BLACK, BLACK, BLACK, BLACK, RED, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK,BLACK,RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, RED, RED, RED, RED, BLACK, BLACK, BLACK,  BLACK,
    BLACK, WHITE, WHITE, BLACK,RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, RED, RED, RED, RED, BLACK, WHITE, WHITE,   BLACK,
    WHITE, PURPLE, PURPLE,BLACK, RED, RED, RED, RED, RED, WHITE, WHITE, RED, RED, RED, RED, RED, BLACK, PURPLE, PURPLE, WHITE,//HERE
    WHITE, PURPLE, PURPLE, BLACK,RED, RED, RED, RED, RED, WHITE, WHITE, RED, RED, RED, RED, RED, BLACK, PURPLE, PURPLE,  WHITE,
    WHITE, PURPLE, PURPLE, BLACK,RED, RED, RED, RED, RED, WHITE, WHITE, RED, RED, RED, RED, RED, BLACK, PURPLE, PURPLE,  WHITE,
    WHITE, PURPLE, PURPLE, BLACK,RED, RED, RED, RED, RED, WHITE, WHITE, RED, RED, RED, RED, RED, BLACK, PURPLE, PURPLE,  WHITE,
    BLACK, BLACK, BLACK, BLACK,RED, RED, RED, RED, RED, WHITE, WHITE, RED, RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, //HERE 
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
    BLACK, BLACK, BLACK,BLACK, BLACK, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, BLACK, BLACK, BLACK, BLACK, BLACK, 
    
};

unsigned char Car2[] = { 
    BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLUE, BLACK, BLACK, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK,CYAN, CYAN, YELLOW, YELLOW, CYAN, BLUE, BLUE, BLUE, BLUE, CYAN, YELLOW, YELLOW, CYAN, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, CYAN, CYAN, CYAN, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, CYAN, CYAN, CYAN, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK, WHITE, WHITE, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, WHITE, WHITE, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, BLACK, BLACK, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLACK, BLACK, BLACK, BLACK, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK,BLACK,BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK,  BLACK,
    BLACK, WHITE, WHITE, BLACK,BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLACK, WHITE, WHITE,   BLACK,
    WHITE, PURPLE, PURPLE,BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, PURPLE, PURPLE, WHITE,//HERE
    WHITE, PURPLE, PURPLE, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, PURPLE, PURPLE,  WHITE,
    WHITE, PURPLE, PURPLE, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, PURPLE, PURPLE,  WHITE,
    WHITE, PURPLE, PURPLE, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, PURPLE, PURPLE,  WHITE,
    BLACK, BLACK, BLACK, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, //HERE 
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
    BLACK, BLACK, BLACK,BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, 
    
};
unsigned char Car3[]={
    BLACK, BLACK, BLACK,BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, 
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
    BLACK, BLACK, BLACK, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, 
    WHITE, PURPLE, PURPLE, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, PURPLE, PURPLE,  WHITE,
    WHITE, PURPLE, PURPLE, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, PURPLE, PURPLE,  WHITE,
    WHITE, PURPLE, PURPLE, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, PURPLE, PURPLE,  WHITE,
    WHITE, PURPLE, PURPLE, BLACK,BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, PURPLE, PURPLE,  WHITE,
    BLACK, WHITE, WHITE, BLACK,BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLACK, WHITE, WHITE,   BLACK,
    BLACK, BLACK, BLACK,BLACK,BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLACK, BLACK, BLACK, BLACK, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, BLACK, BLACK, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, WHITE,PURPLE, PURPLE, BLACK, BLUE, BLUE, WHITE, WHITE, BLUE, BLUE, BLACK, PURPLE, PURPLE, WHITE, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK, BLACK, WHITE, WHITE, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, WHITE, WHITE, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,  BLACK,
    BLACK, BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, CYAN, CYAN, CYAN, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, CYAN, CYAN, CYAN, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, CYAN, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK, BLACK,CYAN, CYAN, YELLOW, YELLOW, CYAN, BLUE, BLUE, BLUE, BLUE, CYAN, YELLOW, YELLOW, CYAN, CYAN, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLUE, BLACK, BLACK, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK,
    BLACK, BLACK,BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLUE, BLUE, BLUE, BLUE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, 
};

unsigned char Person[] = {
    GREEN, GREEN, GREEN, YELLOW, YELLOW, YELLOW, YELLOW, GREEN, GREEN,
    GREEN, GREEN, YELLOW, YELLOW, WHITE, WHITE, YELLOW, YELLOW, GREEN,    
    GREEN, GREEN, YELLOW, WHITE, WHITE, CYAN, WHITE, GREEN, GREEN,
    GREEN, GREEN, YELLOW, WHITE, WHITE, WHITE, WHITE, GREEN, GREEN,    
    GREEN, GREEN, GREEN, WHITE, WHITE, WHITE, GREEN, GREEN, GREEN,    
    GREEN, GREEN, BLUE, WHITE, WHITE, WHITE, BLUE, GREEN, GREEN,   
    GREEN, BLUE, BLUE, BLUE, WHITE, BLUE, BLUE, BLUE, GREEN,   
    GREEN, WHITE, BLUE, BLUE, BLACK, BLUE, BLUE, WHITE, GREEN,
    GREEN, WHITE, BLUE, BLUE, BLACK, BLUE, BLUE, WHITE, GREEN,   
    GREEN, WHITE, BLUE, BLUE, BLACK, BLUE, BLUE, WHITE, GREEN,
    GREEN, GREEN, BLACK, BLACK, RED, BLACK, BLACK, GREEN, GREEN,
    GREEN, GREEN, CYAN, CYAN, CYAN, CYAN, CYAN, GREEN, GREEN,
    GREEN, GREEN, CYAN, CYAN, GREEN, CYAN, CYAN, GREEN, GREEN,
    GREEN, GREEN, GREEN, WHITE, GREEN, WHITE, GREEN, GREEN, GREEN,
    GREEN, GREEN, GREEN, WHITE, GREEN, WHITE, GREEN, GREEN, GREEN,
    GREEN, GREEN, GREEN, WHITE, GREEN, WHITE, GREEN, GREEN, GREEN,
    GREEN, GREEN, RED, RED, GREEN, RED, RED, GREEN, GREEN,     

};

unsigned char Cone[] = {
   RED,BLACK,RED,BLACK,RED,
   WHITE,WHITE,WHITE,WHITE,WHITE,
   BLACK,WHITE,WHITE,WHITE,BLACK,
   WHITE,WHITE,WHITE,WHITE,WHITE,
};
unsigned char Trap[] = { 
    BLACK,WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, RED, WHITE, RED, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK,
    WHITE,WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
};

 struct Line lines[LineAmount];

void setup(){

   
  VGA.begin(VGAWISHBONESLOT(9),CHARMAPWISHBONESLOT(10));
  
  
  VGA.clear();
  VGA.setBackgroundColor(BLACK);
  VGA.setColor(RED);
  VGA.printtext(0,0,"Death Race");
  VGA.printtext(25,10,"Color Bar Test");
  int  i,x1 =73, x2=107,y1=0, y2=0;
   for(i = 0 ; i<LineAmount;i++)
   {
      lines[i].x1 = x1;
       lines[i].y1= y1;
      lines[i].x2 =x2;
     lines[i].y2 = y2;
     y1=y2+=20;
        
   }
  //DrawLimits();

  //Loading();
  
}

void Loading(){
  
  /*for(int i = 0; i < 100; i++){
    if(i%2==0){
      VGA.putPixel(i, 71, GREEN);
      VGA.putPixel(i, 70, GREEN);
    }else{ 
      VGA.putPixel(i, 71, CYAN);
      VGA.putPixel(i, 70, CYAN);
    }
    delay(50);
  
  }*/
  char* buffer;
  
  for(int i = 0; i < 100; i++){
    //itoa(i, buffer, 10);
    if(i%2==0){
      VGA.putPixel(i, 75, WHITE);
      VGA.putPixel(i, 74, WHITE);
    }else{ 
      VGA.putPixel(i, 75, CYAN);
      VGA.putPixel(i, 74, CYAN);
    }

    VGA.printtext(i+5, 72, buffer);
    delay(1000);
  
  }
}

void DrawLimits(){
  for(int i =0 ; i<120; i++){
    if(i%4==0){
      //LEFT
      VGA.putPixel(41, i, WHITE);
      VGA.putPixel(42, i, WHITE);

      //RIGHT
      VGA.putPixel(141, i, WHITE);
      VGA.putPixel(142, i, WHITE);

    }
    //LEFT
    VGA.putPixel(40, i, WHITE);
    VGA.putPixel(43, i, WHITE);
    //RIGHT
    VGA.putPixel(140, i, WHITE);
    VGA.putPixel(143, i, WHITE);
  }
}

void DrawObject(){
    
      VGA.clear();
      VGA.writeArea(83, 85, 20, 29, Car);
       // VGA.writeArea(105, 70-(i*8), 20, 29, Car2);
      
      VGA.setColor( GREEN );
        
        VGA.drawRect( 0, 10, 40, 118 );
        VGA.drawRect( 144, 0, 15, 119 );
        VGA.setBackgroundColor(CYAN);
        VGA.setColor( BLACK );
        VGA.printtext(0,0,"Score");
        VGA.setColor( RED );
        VGA.printtext(0,8,"10000");
        VGA.writeArea(30, 80, 9, 17, Person);
        DrawLines();
        DrawLimits();
        DrawObstacules();
    
      
    
     
   
    //TESTING DIMENSIONS
    VGA.putPixel(0,0,GREEN);
    VGA.putPixel(0,119,RED);
    VGA.putPixel(158,0,GREEN);
    VGA.putPixel(158,119,GREEN);

}
void DrawLine(int posX, int posY)
{
   VGA.setColor( WHITE );
   VGA.drawRect( posX, posY, 4, 6 );
   
}

void DrawObstacules()
{
      if(x*5 >95){
        x=0;
        object++;
        if(object>2)
         object=0; 
      }
      if(object==0)
        VGA.writeArea(116, 0+(x*5), 20, 29, Car3);  //posx =48 primera fila ,posx=83 segunda fila, posx=116 tercera fila
      else if(object==1)
        VGA.writeArea(55, 0+(x*6), 5, 4, Cone); // posx =55 primera fila ,posx=90 segunda fila, posx=123 tercera fila
      else if(object==2)
        VGA.writeArea(48, 0+(x*6), 19, 2, Trap); // posx =55 primera fila ,posx=90 segunda fila, posx=123 tercera fila
      x++;
    
}

void DrawLines()
{
  
   int i ;
   
   for(i = 0;i<LineAmount;i++)
   {
     DrawLine(lines[i].x1, lines[i].y1) ;
     DrawLine(lines[i].x2, lines[i].y2) ;
     if( lines[i].y1>110)
       lines[i].y1=0;
     if( lines[i].y2>110)
       lines[i].y2=0;
     lines[i].y1+=10;
     lines[i].y2+=10;
   }
}



  
void loop(){
  DrawObject();
  delay(500);
}