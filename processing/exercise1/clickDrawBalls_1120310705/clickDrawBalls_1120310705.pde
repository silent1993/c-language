//3
void setup()
{
  size(500,500);
  background(255);
  smooth();
}
void draw()
{
  
}
void mousePressed()
{
  float radius=random(1,width/2);
  int red=(int)random(0,256);
 int green=(int)random(0,256);
 int blue=(int)random(0,256);
 fill(red,green,blue);
 ellipse(mouseX,mouseY,radius,radius);
}

