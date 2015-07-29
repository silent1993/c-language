int radius;
int posx,posy;
int car_len;
void setup()
{
  size(500,500);
  smooth();
 background(255);
  
  strokeWeight(20);
  posx=500;
  posy=500;
  car_len=80;
}
void draw()
{
   background(255);
  radius=900;
  noFill();
  stroke(139,0,255);
  ellipse(500,500,radius,radius);
  radius+=20;
   stroke(0,0,255);
  ellipse(500,500,radius,radius);
  radius+=20;
   stroke(0,127,255);
  ellipse(width,height,radius,radius);
  radius+=20;
   stroke(0,255,0);
  ellipse(width,height,radius,radius);
  radius+=20;
   stroke(255,255,0);
  ellipse(width,height,radius,radius);
  radius+=20;
   stroke(255,165,0);
  ellipse(width,height,radius,radius);
  radius+=20;
   stroke(255,0,0);
  ellipse(width,height,radius,radius);
  radius+=20;
 draw_bus();
}
void draw_bus()
{
 
  int offset=car_len/4;
  noStroke();
  fill(0);
  rect(posx,posy-car_len/2-5,car_len,car_len/2);
  ellipse(posx+offset,posy-5,10,10);
  ellipse(posx+3*offset,posy-5,10,10);
  posx--;
  if(posx+car_len<=0)
  posx=500;
}

