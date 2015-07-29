using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace DriveFast
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;


        private Texture2D mCar;
        private Texture2D mBackground;
        private Texture2D mRoad;
        private Texture2D mHazard;

        private KeyboardState mPreviousKeyboardState;

        private Vector2 mCarPosition = new Vector2(280, 440);
        private int mCarTemp;
        private int mMoveCarX = 160;
        private int mVelocityY;
        private double mNextHazardAppearsIn, mmNextHazardAppearsIn;
        private int mCarsRemaining;
        private int mHazardsPassed;
        private int mIncreaseVelocity;
        private double mExitCountDown = 10;

        private int[] mRoadY = new int[2];
    
        private List<Hazard> mHazards = new List<Hazard>();

        // 定义随机数 - 比方用来表示障碍物的位置
        private Random mRandom = new Random();

        private SpriteFont mFont;

        //----------------------- Feng ---------------------
        // 自定义枚举类型，表明不同的游戏状态
        private enum State
        {
            TitleScreen,      // 初始片头
            Running,
            Crash,           // 碰撞
            GameOver,
            Success
        }
        //--------------------- Tian --------------------------


        private State mCurrentState = State.TitleScreen;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";

            // 定义游戏窗口大小
            graphics.PreferredBackBufferHeight = 600;
            graphics.PreferredBackBufferWidth = 837;
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            mCar = Content.Load<Texture2D>("Images/Car");
            mBackground = Content.Load<Texture2D>("Images/Background");
            mRoad = Content.Load<Texture2D>("Images/Road");
            mHazard = Content.Load<Texture2D>("Images/Car");

            // 定义字体
            mFont = Content.Load<SpriteFont>("MyFont");
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        protected void StartGame()
        {
            mRoadY[0] = 0;
            mRoadY[1] = -1 * mRoad.Height;
          
            mHazardsPassed = 0;
            mCarsRemaining = 3; // 所剩车辆的数量
            mVelocityY = 3;
            mNextHazardAppearsIn = 1.5;
            mIncreaseVelocity = 5;  // 速度递增
            mmNextHazardAppearsIn = 1.5;
            mHazards.Clear();

            mCurrentState = State.Running;
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            KeyboardState aCurrentKeyboardState = Keyboard.GetState();

            //Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed ||
                aCurrentKeyboardState.IsKeyDown(Keys.Escape) == true)
            {
                this.Exit();
            }

            switch (mCurrentState)
            {
                case State.TitleScreen:
                case State.Success:
                case State.GameOver:
                    {
                        ExitCountdown(gameTime);

                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {
                            StartGame();
                        }
                        break;
                    }

                case State.Running:
                    {
                        //If the user has pressed the Spacebar, then make the car switch lanes
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Left) == true && mPreviousKeyboardState.IsKeyDown(Keys.Left) == false)
                        {
                
                            mCarPosition.X -= mMoveCarX;
                           // mMoveCarX *= -1;
                            if (mCarPosition.X <= 0)
                            {
                                mCarPosition.X += mRoad.Width-200;
                            }

                        }
                        else  if (aCurrentKeyboardState.IsKeyDown(Keys.Right) == true && mPreviousKeyboardState.IsKeyDown(Keys.Right) == false)
                        {
                            mCarPosition.X += mMoveCarX;
                            // mMoveCarX *= -1;
                            if (mCarPosition.X >= this.Window.ClientBounds.Width)
                            {
                                mCarPosition.X -= mRoad.Width+200;
                            }
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Up) == true)
                        {
                            for (int aIndex = 0; aIndex < mRoadY.Length; aIndex++)
                            {
                                mRoadY[aIndex] += mVelocityY;
                            }
                           
                           

                        }
                        ScrollRoad();
  
                        foreach (Hazard aHazard in mHazards)
                        {
                            if (CheckCollision(aHazard) == true)
                            {
                                break;
                            }

                            MoveHazard(aHazard);
                        }

                        UpdateHazards(gameTime);
                        break;
                    }
                case State.Crash:
                    {
                        //If the user has pressed the Space key, then resume driving
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {
                            mHazards.Clear();
                            mCurrentState = State.Running;
                        }

                        break;
                    }
            }
            mPreviousKeyboardState = aCurrentKeyboardState;

            base.Update(gameTime);
        }

        //----------------------- Feng ---------------------
        // 让路面向后移动（使车辆看起来在往前行）
        private void ScrollRoad()
        {
            //Move the scrolling Road
            for (int aIndex = 0; aIndex < mRoadY.Length; aIndex++)
            {
                if (mRoadY[aIndex] >= this.Window.ClientBounds.Height) // 检测路面有没有移出游戏窗口
                {
                    int aLastRoadIndex = aIndex;
                    for (int aCounter = 0; aCounter < mRoadY.Length; aCounter++)
                    {
                        if (mRoadY[aCounter] < mRoadY[aLastRoadIndex])
                        {
                            aLastRoadIndex = aCounter;
                        }
                    }
                    mRoadY[aIndex] = mRoadY[aLastRoadIndex] - mRoad.Height; // 改变Y坐标，让路移动
                }
            }

        
        }


    
        //----------------------- Tian ---------------------

        private void MoveHazard(Hazard theHazard)
        {
            theHazard.Position.Y += mVelocityY;
            if (theHazard.Position.Y > graphics.GraphicsDevice.Viewport.Height && theHazard.Visible == true)
            {
                theHazard.Visible = false;
                mHazardsPassed += 1;

                if (mHazardsPassed >= 100) // 如果通过100个障碍物，成功！
                {
                    mCurrentState = State.Success;
                    mExitCountDown = 10;
                }

                mIncreaseVelocity -= 1;
                if (mIncreaseVelocity < 0)
                {
                    mIncreaseVelocity = 5;
                    mVelocityY += 1;
                }
            }
        }

        private void UpdateHazards(GameTime theGameTime)
        {
            mNextHazardAppearsIn -= theGameTime.ElapsedGameTime.TotalSeconds;// 游戏运行的时间
             
            if (mNextHazardAppearsIn < 0)
            {
                int aLowerBound = 24 - (mVelocityY * 2);
                int aUpperBound = 30 - (mVelocityY * 2);

                if (mVelocityY > 10)
                {
                    aLowerBound = 6;
                    aUpperBound = 8;
                }

                // 控制障碍物出现的位置（随机）
                mNextHazardAppearsIn = (double)mRandom.Next(aLowerBound, aUpperBound) / 10;
                
                AddHazard();
            }
            
        }

        private void AddHazard()
        {
            int aRoadPosition = mRandom.Next(1, 5);
            int aPosition = 275;
            if (aRoadPosition == 2)
            {
                aPosition = 440;
            }
            else  if (aRoadPosition == 3)
            {
                aPosition = 565;
            }
            else if (aRoadPosition == 4)
            {
                aPosition = 125;
            }
            bool aAddNewHazard = true;
            foreach (Hazard aHazard in mHazards)
            {
                if (aHazard.Visible == false)
                {
                    aAddNewHazard = false;
                    aHazard.Visible = true;
                    aHazard.Position = new Vector2(aPosition, -mHazard.Height);
                    break;
                }
            }

            if (aAddNewHazard == true)
            {
                //Add a hazard to the left side of the Road
                Hazard aHazard = new Hazard();
                aHazard.Position = new Vector2(aPosition, -mHazard.Height);

                mHazards.Add(aHazard);
            }
        }

        //----------------------- Feng ------------------------------------------------
        // 检测车辆是否碰到了障碍物
        private bool CheckCollision(Hazard theHazard)
        {
            // 分别计算并使用封闭（包裹）盒给障碍物和车
            BoundingBox aHazardBox = new BoundingBox(new Vector3(theHazard.Position.X, theHazard.Position.Y, 0), new Vector3(theHazard.Position.X + (mHazard.Width * .2f), theHazard.Position.Y + ((mHazard.Height - 50) * .2f), 0));
            BoundingBox aCarBox = new BoundingBox(new Vector3(mCarPosition.X, mCarPosition.Y, 0), new Vector3(mCarPosition.X + (mCar.Width * .2f), mCarPosition.Y + (mCar.Height * .2f), 0));

            if (aHazardBox.Intersects(aCarBox) == true) // 碰上了吗?
            {
                mCurrentState = State.Crash;
                mCarsRemaining -= 1;
                if (mCarsRemaining < 0)
                {
                    mCurrentState = State.GameOver;
                    mExitCountDown = 10;
                }
                return true;
            }

            return false;
        }
        //----------------------- Tian ------------------------------------------------------

        private void ExitCountdown(GameTime theGameTime)
        {
            mExitCountDown -= theGameTime.ElapsedGameTime.TotalSeconds;
            if (mExitCountDown < 0)
            {
                this.Exit();
            }
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            graphics.GraphicsDevice.Clear(Color.CornflowerBlue);

            spriteBatch.Begin();

            spriteBatch.Draw(mBackground, new Rectangle(graphics.GraphicsDevice.Viewport.X, graphics.GraphicsDevice.Viewport.Y, graphics.GraphicsDevice.Viewport.Width, graphics.GraphicsDevice.Viewport.Height), Color.White);

            switch (mCurrentState)
            {
                case State.TitleScreen:
                    {
                        //Draw the display text for the Title screen
                        DrawTextCentered("Drive Fast And Avoid the Oncoming Obstacles", 200);
                        DrawTextCentered("Press 'Space' to begin", 260);
                        DrawTextCentered("Exit in " + ((int)mExitCountDown).ToString(), 475);

                        break;
                    }

                default:
                    {
                        DrawRoad();
                        DrawHazards();

                        spriteBatch.Draw(mCar, mCarPosition, new Rectangle(0, 0, mCar.Width, mCar.Height), Color.White, 0, new Vector2(0, 0), 0.2f, SpriteEffects.None, 0);

                        spriteBatch.DrawString(mFont, "Cars:", new Vector2(28, 520), Color.Brown, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);
                        for (int aCounter = 0; aCounter < mCarsRemaining; aCounter++)
                        {
                            spriteBatch.Draw(mCar, new Vector2(25 + (30 * aCounter), 550), new Rectangle(0, 0, mCar.Width, mCar.Height), Color.White, 0, new Vector2(0, 0), 0.05f, SpriteEffects.None, 0);
                        }

                        spriteBatch.DrawString(mFont, "Hazards: " + mHazardsPassed.ToString(), new Vector2(5, 25), Color.Brown, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);

                        if (mCurrentState == State.Crash)
                        {
                            DrawTextDisplayArea();

                            DrawTextCentered("Crash!", 200);
                            DrawTextCentered("Press 'Space' to continue driving.", 260);
                        }
                        else if (mCurrentState == State.GameOver)
                        {
                            DrawTextDisplayArea();

                            DrawTextCentered("Game Over.", 200);
                            DrawTextCentered("Press 'Space' to try again.", 260);
                            DrawTextCentered("Exit in " + ((int)mExitCountDown).ToString(), 400);

                        }
                        else if (mCurrentState == State.Success)
                        {
                            DrawTextDisplayArea();

                            DrawTextCentered("Congratulations!", 200);
                            DrawTextCentered("Press 'Space' to play again.", 260);
                            DrawTextCentered("Exit in " + ((int)mExitCountDown).ToString(), 400);
                        }

                        break;
                    }
            }
            spriteBatch.End();

            base.Draw(gameTime);
        }

        private void DrawRoad()
        {
            for (int aIndex = 0; aIndex < mRoadY.Length; aIndex++)
            {
                if (mRoadY[aIndex] > mRoad.Height * -1 && mRoadY[aIndex] <= this.Window.ClientBounds.Height)
                {
                    spriteBatch.Draw(mRoad, new Rectangle((int)((this.Window.ClientBounds.Width - mRoad.Width) / 2 - 18), mRoadY[aIndex], mRoad.Width, mRoad.Height + 5), Color.White);
                }
            }
        }

        private void DrawHazards()
        {
            foreach (Hazard aHazard in mHazards)
            {
                if (aHazard.Visible == true)
                {
                    spriteBatch.Draw(mHazard, aHazard.Position, new Rectangle(0, 0, mHazard.Width, mHazard.Height), Color.White, 0, new Vector2(0, 0), 0.2f, SpriteEffects.None, 0);
                }
            }
        }

        private void DrawTextDisplayArea()
        {
            int aPositionX = (int)((graphics.GraphicsDevice.Viewport.Width / 2) - (450 / 2));
            spriteBatch.Draw(mBackground, new Rectangle(aPositionX, 75, 450, 400), Color.White);
        }

        private void DrawTextCentered(string theDisplayText, int thePositionY)
        {
            Vector2 aSize = mFont.MeasureString(theDisplayText);
            int aPositionX = (int)((graphics.GraphicsDevice.Viewport.Width / 2) - (aSize.X / 2));

            spriteBatch.DrawString(mFont, theDisplayText, new Vector2(aPositionX, thePositionY), Color.Beige, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);
            spriteBatch.DrawString(mFont, theDisplayText, new Vector2(aPositionX + 1, thePositionY + 1), Color.Brown, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);
        }
    }
}
