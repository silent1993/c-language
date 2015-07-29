class ball{
  float ball_x,ball_y;
  color c;
  float dia;
  int flag;
  float click_x;
  float click_y;
  int hasdraw;
  int isValid;
  ball()
  {
    ball_x=100;
    ball_y=100;
     flag=0;
     dia=100;
  }
  
  void draw_ball()
  {
    if(flag!=1&&hasdraw!=1)
     {
       c=color(random(0,255),random(0,255),random(0,255));
       background(255);
       fill(c);
       ellipse(ball_x,ball_y,dia,dia);
       hasdraw=1;
     }
     else if(flag==1)
     {
       background(255);
       fill(c);
       float dis_x=click_x-mouseX;
       float dis_y=click_y-mouseY;
       ellipse(ball_x-dis_x,ball_y-dis_y,dia,dia);
     }
     if(isValid==0)
     {
       background(255);
       fill(c);
       ellipse(ball_x,ball_y,dia,dia);
       isValid=1;
     }
  }
  
}
ball myball;
void setup()
{
  
  size(400,400);
  smooth();
  stroke(0);
 
  myball=new ball();
  background(255);
  // myball.draw_ball();
}
void draw()
{
   myball.draw_ball();
   line(width/2,0,width/2,height);
   line(0,height/2,width,height/2);
}
void mousePressed()
  {
    float dis=dist(mouseX,mouseY,myball.ball_x,myball.ball_y);
    if(dis<=myball.dia/2)
      {
        myball.flag=1;
       myball.click_x=mouseX;
       myball.click_y=mouseY;
      }
    
  }
  boolean notOut()
{
  if(mouseX>=0&&mouseX<=width&&mouseY>=0&&mouseY<=height)
   return true;
   else
   return false;
}

void mouseReleased()
  {
    if(myball.flag==1&&notOut())
    {
      
      myball.flag=0;
    if(mouseX<200&&mouseY<200)
    {
      myball.ball_x=100;
      myball.ball_y=100;
    }
    else if(mouseX>200&&mouseY<200)
    {
      myball.ball_x=300;
      myball.ball_y=100;
    }
    else if(mouseX<200&&mouseY>200)
    {
      myball.ball_x=100;
      myball.ball_y=300;
      
    }
    else 
    {
     myball.ball_x=300;
      myball.ball_y=300;
    }
    myball.hasdraw=0;
    
    }
    if(!notOut())
    {
      myball.isValid=0;
      myball.flag=0;
    }
    
    
     //myball.draw_ball();
  }

