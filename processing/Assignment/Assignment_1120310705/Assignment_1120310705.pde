final int cellWidth = 40;
final int cellHeight = cellWidth;
color[][] grid = new color[15][15];
//used to draw the grid
void drawGrid()
{
  for (int i = 0; i < grid.length; i++) {
    for (int j = 0; j < grid[0].length; j++) {
     stroke(0);
     noFill();
     rect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
    }
  }
}
//the class of the ball
class Ball{
  int dia;
  int[][] is_ball=new int[15][15];//to show where is a ball
  float offsetx,offsety;
  int isClick;
  color drag_color;
  Ball()
  {
    for(int i=0;i<grid[0].length;i++)
    {
      grid[grid.length-1][i]=color(random(0,255),random(0,255),random(0,255));
      is_ball[grid.length-1][i]=1;
    }
    dia=cellHeight-10;
    isClick=0;
  }
  //to draw ball
  void draw_ball()
  {
    for(int i=0;i<grid.length;i++)
    {
      for(int j=0;j<grid[0].length;j++)
      {
        if(is_ball[i][j]==1)
        {
          noStroke();
          fill(grid[i][j]);
          ellipse((j*cellWidth+cellWidth/2),(i*cellHeight+cellHeight/2),dia,dia);
        }
      }
    }
  }
  //if the mouse is pressed
  void mouseClick()
  {
    int row,col;
    col=mouseX/cellWidth;
    row=mouseY/cellHeight;
    
    //float offsetx,offsety;
    float dis=dist(mouseX,mouseY,(col*cellWidth+cellWidth/2),(row*cellHeight+cellHeight/2));
    if(dis<=dia/2)
    {
      //println("yuuahnaj");
     offsetx=mouseX- (col*cellWidth+cellWidth/2);
     offsety=mouseY-(row*cellHeight+cellHeight/2);
     isClick=1;
     drag_color=grid[row][col];
    }
  }
  //if the mouse is dragged
  void mouseDrag(Square s)
  {
    if(isClick==1)
    {
      noStroke();
     
      background(255);
     s.draw_square();
     draw_ball();
      fill(drag_color);
      ellipse(mouseX-offsetx,mouseY-offsety,dia,dia);
        drawGrid();
  
    }
    
  }
  //if the mouse is released
  void mouseRelease(Square s)
  {
     int row,col;
    col=mouseX/cellWidth;
    row=mouseY/cellHeight;
    background(255);
     if(row>=grid.length||row<0||col>=grid[0].length||col<0)
    {
       isClick=0;
        drawGrid();
  draw_ball();
  s.draw_square();
      return;
    }
    else if(row!=(grid.length-1)&&isClick==1)
    {
      s.is_square[row][col]=0;
    grid[row][col]=drag_color;
    //float offsetx,offsety;
   is_ball[row][col]=1;
   isClick=0;
    }
     drawGrid();
  draw_ball();
  s.draw_square();
  }
  //if the space is pressed ,to init the ball
  void init()
  {
    for(int i=0;i<grid.length;i++)
    {
      for(int j=0;j<grid[0].length;j++)
      {
        is_ball[i][j]=0;
      }
    }
    for(int i=0;i<grid[0].length;i++)
    {
      
     
      is_ball[grid.length-1][i]=1;
    }
    
    isClick=0;
  }
  
}
class Square{
   int wid,hei;
  int[][] is_square=new int[15][15];//to show where is a square
   float offsetx,offsety;
  int isClick;
  color drag_color;
  Square()
  {
    for(int i=0;i<grid[0].length;i++)
    {
      grid[0][i]=color(random(0,255),random(0,255),random(0,255));
      is_square[0][i]=1;
    }
   wid=cellWidth-10;
   hei=wid;
   isClick=0;
  }
  //to draw the square
  void draw_square()
  {
    for(int i=0;i<grid.length;i++)
    {
      for(int j=0;j<grid[0].length;j++)
      {
        if(is_square[i][j]==1)
        {
          noStroke();
          fill(grid[i][j]);
          rect((j*cellWidth+5),(i*cellHeight+5),wid,hei);
        }
      }
    }
  }
  //if the mouse is pressed
  void mouseClick()
  {
    int row,col;
    col=mouseX/cellWidth;
    row=mouseY/cellHeight;
    if(mouseX>=(col*cellWidth+5)&&mouseX<=((col+1)*cellWidth-5)&&mouseY>=(row*cellHeight+5)&&mouseY<=((row+1)*cellHeight-5))//to judge if the mouse is in the square
    {
      //println("click");
      //println(mouseX);
      //println(mouseY);
     offsetx=mouseX- col*cellWidth;
     offsety=mouseY-row*cellHeight;
     isClick=1;
     drag_color=grid[row][col];
    }
  }
  //if the mouse is dragged
  void mouseDrag(Ball b)
  {
    if(isClick==1)
    {
     // println("isdrag");
      noStroke();
     background(255);
      draw_square();
     b.draw_ball();
      fill(drag_color);
      rect((mouseX-offsetx+5),(mouseY-offsety+5),wid,hei);
     drawGrid();
    
    }
    
  }
  //if the mouse is released
  void mouseRelease(Ball b)
  {
     int row,col;
    col=mouseX/cellWidth;
    row=mouseY/cellHeight;
    background(255);
    if(row>=grid.length||row<0||col>=grid[0].length||col<0)
    {
       isClick=0;
          drawGrid();
  b.draw_ball();
  draw_square();
      return;
    }
   else if(row!=0&&isClick==1)
    {
      b.is_ball[row][col]=0;
    grid[row][col]=drag_color;
    //float offsetx,offsety;
   is_square[row][col]=1;
   isClick=0;
    }
      drawGrid();
  b.draw_ball();
  draw_square();
  }
  //if the space is pressed
    void init()
  {
    for(int i=0;i<grid.length;i++)
    {
      for(int j=0;j<grid[0].length;j++)
      {
        is_square[i][j]=0;
      }
    }
    for(int i=0;i<grid[0].length;i++)
    {
      
     
      is_square[0][i]=1;
    }
    
    isClick=0;
  }
}
Ball ball;
Square square;
int draw_flag;
void setup(){
  background(255);
  size(cellWidth * grid.length + 1, cellHeight * grid[0].length + 1); 
  ball=new Ball();
  square=new Square();
  draw_flag=0;
   drawGrid();
   smooth();
}

void draw(){
  //background(255);
  if(ball.isClick==0&&square.isClick==0)
 { drawGrid();
  ball.draw_ball();
  square.draw_square();
 }
}

void mousePressed()
{
  
  int col,row;
  row=mouseY/cellHeight;
  col=mouseX/cellWidth;
 // println(row);
  if(square.is_square[row][col]==1)
  {
    square.mouseClick();
    if(square.isClick==1)
      draw_flag=1;
  }
  if(ball.is_ball[row][col]==1)
  {
    ball.mouseClick();
    if(ball.isClick==1)
      draw_flag=2;
  }
 else
 return;
}
void mouseDragged()
{
  //println("ddd");
  if(draw_flag==1)
  {
   
    square.mouseDrag(ball);
    
  }
  else if(draw_flag==2)
  {
    ball.mouseDrag(square);
  }
  else
  return;
}
void mouseReleased()
{
  if(draw_flag==1)
  {
    square.mouseRelease(ball);
    draw_flag=0;
  }
  else if(draw_flag==2)
  {
    ball.mouseRelease(square);
    draw_flag=0;
    
  }
  else
  return;
}
void keyPressed()
{
  if(key==32)
  {
    background(255);
    ball.init();
    square.init();
  }
 
}
 


