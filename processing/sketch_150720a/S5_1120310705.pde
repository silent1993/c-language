color[][] grid;
void setup()
{
  grid=new int[30][30];
  size(300,300);
  for(int i=0;i<30;i++)
  {
    for(int j=0;j<30;j++)
    {
      grid[i][j]=color(random(0,255),random(0,255),random(0,255));
    }
  }
  
}
void draw()
{
  background(255);
  for(int i=0;i<30;i++)
  {
    for(int j=0;j<30;j++)
    {
      fill(grid[i][j]);
      rect(i*10,j*10,i*10+10,j*10+10);
    }
  }
}
void keyPressed()
{
   for(int i=0;i<30;i++)
  {
    for(int j=0;j<30;j++)
    {
      grid[i][j]=color(random(0,255),random(0,255),random(0,255));
    }
  }
}

