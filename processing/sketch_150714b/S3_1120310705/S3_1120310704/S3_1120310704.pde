class ball{
  float x;
  float y;
  color c;
  float dia;
  float speedx;
  float speedy;
  ball(){
    dia=random(20,40);
    x=random(dia/2,width-dia/2);
    y=random(dia/2,height-dia/2);
    speedx=random(-5,5);
    speedy=random(-5,5);
    c=color(random(0,255),random(0,255),random(0,255));
  }
  
  void display(){
    fill(c);
    ellipse(x,y,dia,dia);
  }
  void move()
  {
    x=x+speedx;
    y=y+speedy;
    display();
    if(x-dia/2<0||x+dia/2>width)
      speedx=-speedx;
    if(y-dia/2<0||y+dia/2>height)
       speedy=-speedy;
  }
  boolean isCollision(ball b2)
  {
    float dis=dist(x,y,b2.x,b2.y);
    if(dis<=dia/2+b2.dia/2)
      return true;
     else
       return false;
  }
  
}
ball ball1,ball2;
void setup()
{
  size(400,400);
  ball1=new ball();
  ball2=new ball();
}
void draw()
{
  background(255);
  if(ball1.isCollision(ball2))
    {
      ball1.display();
      ball2.display();
    }
    else
    {
      ball1.move();
      ball2.move();
    }
}
