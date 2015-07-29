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


        private Texture2D[] mCar=new Texture2D[3];
        private Texture2D mBackground;
        private Texture2D mRoad;
        private Texture2D mHazard;
        private Texture2D mCar2;
        private KeyboardState mPreviousKeyboardState;

        private Vector2 mCarPosition = new Vector2(280, 440);
        private int mMoveCarX = 145;
        private int mVelocityY;


        AudioEngine audioengine;
        WaveBank wavebank;
        SoundBank soundbank;
        AudioEngine audioengine2;
        Cue cue1;
        WaveBank bank2;
        SoundBank sound2;

        private int flag;
        private int flag1;
        private int flag2;
        private int flag3;

        bool playy;

        private bool icc;
        private bool icd;

        private double mNextHazardAppearsIn;
        private double mNextHazardAppearsIn2;
        private int mCarsRemaining;
        private int mHazardsPassed;
        private int mIncreaseVelocity;
        private double mExitCountDown = 10;

        private int[] mRoadY = new int[2];
        private List<Hazard> mHazards = new List<Hazard>();
        private List<Hazard> mHazards2 = new List<Hazard>();
        // 定义随机数 - 比方用来表示障碍物的位置
        private Random mRandom = new Random();
      
        private SpriteFont mFont;

        //----------------------- Feng ---------------------
        // 自定义枚举类型，表明不同的游戏状态
        private enum State
        {
            TitleScreen,      // 初始片头
            Running,
            Diff,
            ChooseCar,
            Option,
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
            graphics.PreferredBackBufferWidth = 800;
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


            flag = 1;
            flag1 = 1;
            flag2 = 1;
            flag3 = 1;//用于选择的标记

            playy = false;
            icc = false;
            icd = false;

            mCar[0] = Content.Load<Texture2D>("Images/Car");
            mCar[1] = Content.Load<Texture2D>("Images/Car3");
            mCar[2] = Content.Load<Texture2D>("Images/Car1");
            mBackground = Content.Load<Texture2D>("Images/Background");
            mRoad = Content.Load<Texture2D>("Images/Road");
            mHazard = Content.Load<Texture2D>("Images/Hazard");
            mCar2 = Content.Load<Texture2D>("Images/Car2");
            // 定义字体
            mFont = Content.Load<SpriteFont>("MyFont");


            audioengine2 = new AudioEngine("content/Audio/Looplay.xgs");
            sound2 = new SoundBank(audioengine2, "content/Audio/sound2.xsb");
            bank2 = new WaveBank(audioengine2, "content/Audio/bank2.xwb");
            audioengine = new AudioEngine("content/Audio/Audio.xgs");
            wavebank = new WaveBank(audioengine, "content/Audio/mWave.xwb");
            soundbank = new SoundBank(audioengine, "content/Audio/mSound.xsb");

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
            mNextHazardAppearsIn2 = 2.0;
            mIncreaseVelocity = 5;  // 速度递增

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
                case State.TitleScreen://开始菜单
                    {
                        ExitCountdown(gameTime);
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Up) == true && mPreviousKeyboardState.IsKeyDown(Keys.Up) == false)
                        {
                            if (flag != 1)
                                flag--;
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Down) == true && mPreviousKeyboardState.IsKeyDown(Keys.Down) == false)
                        {
                            if (flag != 5)
                                flag++;
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {
                            StartGame();
                            if (flag == 1)
                            {
                                if(icc&&icd)
                                mCurrentState = State.Running;
                                if(!icc)
                                    mCurrentState = State.ChooseCar;
                                if(!icd)
                                mCurrentState = State.Diff;

                            }
                            if (flag == 2)
                                mCurrentState = State.Option;
                            if (flag == 3)
                            {
                                mCurrentState = State.ChooseCar;
                               // icc = true;
                            }
                            if (flag == 4)
                            {
                                mCurrentState = State.Diff;
                               // icd = true;
                            }
                            if (flag == 5)
                                this.Exit();

                          
                        }
                        break;
                    }
                case State.Diff://改变游戏难度
                    {
                        icd = true;
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Up) == true && mPreviousKeyboardState.IsKeyDown(Keys.Up) == false)
                        {
                            if (flag3 != 1)
                                flag3--;
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Down) == true && mPreviousKeyboardState.IsKeyDown(Keys.Down) == false)
                        {
                            if (flag3 != 3)
                                flag3++;
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {

                            if (flag3 == 1)
                            {
                                mVelocityY = 3;
                            }
                            if (flag3 == 2)
                                mVelocityY = 6;
                            if (flag3 == 3)
                                mVelocityY = 9;
                           if(icc==true)
                            mCurrentState = State.Running;
                           if(!icc)
                               mCurrentState = State.ChooseCar;
                        }
                        break;
                    }
                case State.Success:
                    {
                        int[] temp={flag,flag1,flag2,flag3};
                        ExitCountdown(gameTime);
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {
                            
                            StartGame();
                            flag = temp[0];
                            flag1 = temp[1];
                            flag2 = temp[2];
                            flag3 = temp[3];
                            if (flag3 == 1)
                            {
                                mVelocityY = 3;
                            }
                            if (flag3 == 2)
                                mVelocityY = 6;
                            if (flag3 == 3)
                                mVelocityY = 9;
                           
                        }
                        break;
                    }
                case State.ChooseCar:
                    {
                        icc = true;
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Up) == true && mPreviousKeyboardState.IsKeyDown(Keys.Up) == false)
                        {
                            if (flag2 != 1)
                                flag2--;
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Down) == true && mPreviousKeyboardState.IsKeyDown(Keys.Down) == false)
                        {
                            if (flag2 != 3)
                                flag2++;
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {


                            if (icd == true)
                                mCurrentState = State.Running;
                            if (!icd)
                                mCurrentState = State.Diff;
                        }


                        
                        break;
                    }
                case State.Option:
                    {
                      
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Up) == true && mPreviousKeyboardState.IsKeyDown(Keys.Up) == false)
                        {
                           

                            if (flag1 != 1)
                                flag1--;
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Down) == true && mPreviousKeyboardState.IsKeyDown(Keys.Down) == false)
                        {
                            if (flag1 != 2)
                                flag1++;
                        }
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {
                          
                            if (flag1 == 1)
                            {
                                graphics.ToggleFullScreen();
                                mCurrentState = State.Option;
                            }
                            if (flag1 == 2)
                                mCurrentState = State.TitleScreen;
                          
                           

                        }
                        break;
                    }

                case State.GameOver:
                    {
                        int[] temp = { flag, flag1, flag2, flag3 };
                        ExitCountdown(gameTime);

                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {
                            StartGame();
                            flag = temp[0];
                            flag1 = temp[1];
                            flag2 = temp[2];
                            flag3 = temp[3];
                            if (flag3 == 1)
                            {
                                mVelocityY = 3;
                            }
                            if (flag3 == 2)
                                mVelocityY = 6;
                            if (flag3 == 3)
                                mVelocityY = 9;
                          
                        }
                        break;
                    }

                case State.Running:
                    {

                        if (!playy)
                        {
                            sound2.PlayCue("Tank");
                            playy = true;
                        }


                  
                        //If the user has pressed the Spacebar, then make the car switch lanes
                        mCarPosition.X = MathHelper.Clamp(mCarPosition.X, 108, Window.ClientBounds.Width - 202);//边界检测
                        mCarPosition.Y = MathHelper.Clamp(mCarPosition.Y, 0, Window.ClientBounds.Height - 150);

                            if (aCurrentKeyboardState.IsKeyDown(Keys.Left) == true )
                            {
                                mCarPosition.X -= mMoveCarX/10;
                              
                            }
                            else if (aCurrentKeyboardState.IsKeyDown(Keys.Right) == true)
                            {
                                mCarPosition.X += mMoveCarX/10;
                                

                            }
                            if (aCurrentKeyboardState.IsKeyDown(Keys.Up) == true)
                            {
                                if (!mPreviousKeyboardState.IsKeyDown(Keys.Up) == true)
                                {
                                    soundbank.PlayCue("E1");
                                }
                                mCarPosition.Y -= mMoveCarX / 10;
                                //  mMoveCarX *= -1;
                            }

                            if (aCurrentKeyboardState.IsKeyDown(Keys.Down) == true)
                            {
                                mCarPosition.Y += mMoveCarX / 10;
                                //mMoveCarX *= 1;
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
                            foreach (Hazard aHazard in mHazards2)
                            {
                                if (CheckCollision2(aHazard) == true)
                                {
                                    break;
                                }

                                MoveHazard2(aHazard);
                            }
                            UpdateHazards(gameTime);
                            UpdateHazards2(gameTime);
                            break;


                        }
                    
                case State.Crash:
                    {
                        
                        //If the user has pressed the Space key, then resume driving
                        if (aCurrentKeyboardState.IsKeyDown(Keys.Space) == true && mPreviousKeyboardState.IsKeyDown(Keys.Space) == false)
                        {
                            mHazards.Clear();
                            mHazards2.Clear();
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

            for (int aIndex = 0; aIndex < mRoadY.Length; aIndex++)
            {
                mRoadY[aIndex] += mVelocityY;
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

                if (mHazardsPassed >= 50) // 如果通过100个障碍物，成功！
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
        private void MoveHazard2(Hazard theHazard)
        {
            theHazard.Position.Y += mVelocityY+5;
            if (theHazard.Position.Y > graphics.GraphicsDevice.Viewport.Height && theHazard.Visible == true)
            {
                theHazard.Visible = false;
                mHazardsPassed += 1;
                if (mHazardsPassed >= 50) // 如果通过100个障碍物，成功！
                {
                    mCurrentState = State.Success;
                    mExitCountDown = 10;
                }

                

             
            }
        }
        private void UpdateHazards(GameTime theGameTime)
        {

            mNextHazardAppearsIn -= theGameTime.ElapsedGameTime.TotalSeconds; // 游戏运行的时间
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


            //AddHazard2();


        }
        private void UpdateHazards2(GameTime theGameTime)
        {

            mNextHazardAppearsIn2 -= theGameTime.ElapsedGameTime.TotalSeconds; // 游戏运行的时间
            if (mNextHazardAppearsIn2 < 0)
            {
                int aLowerBound = 124 - (mVelocityY * 2);
                int aUpperBound = 130 - (mVelocityY * 2);

                if (mVelocityY > 10)
                {
                    aLowerBound = 15;
                    aUpperBound =17;
                }

                // 控制障碍物出现的位置（随机）
                mNextHazardAppearsIn2 = (double)mRandom.Next(aLowerBound, aUpperBound) / 10;

                AddHazard2();

            }


            //AddHazard2();


        }
           

      private void AddHazard()
        {
            int aRoadPosition = mRandom.Next(1,5);
            int aPosition = 275;
            if (aRoadPosition == 2)
            {
                aPosition = 440;
            }
            if (aRoadPosition == 3)
            {
                aPosition = 585;
            }
            if (aRoadPosition == 4)
            {
                aPosition = 135;
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
         private void AddHazard2()
        {
            int aRoadPosition2 = mRandom.Next(1, 5);
            int aPosition2 = 135;
            if (aRoadPosition2 == 2)
            {
                aPosition2 = 440;
            }
            if (aRoadPosition2 == 3)
            {
                aPosition2 = 585;
            }
            if (aRoadPosition2 == 4)
            {
                aPosition2 = 275;
            }

            bool aAddNewHazard2 = true;
            foreach (Hazard aHazard in mHazards2)
            {
                if (aHazard.Visible == false)
                {
                    aAddNewHazard2 = false;
                    aHazard.Visible = true;
                    aHazard.Position = new Vector2(aPosition2, -mCar2.Height);
                    break;
                }
            }

            if (aAddNewHazard2 == true)
            {
                //Add a hazard to the left side of the Road
                Hazard aHazard = new Hazard();
                aHazard.Position = new Vector2(aPosition2, -mCar2.Height);

                mHazards2.Add(aHazard);
            }
        }

        //----------------------- Feng ------------------------------------------------
        // 检测车辆是否碰到了障碍物
        private bool CheckCollision(Hazard theHazard)
        {
            // 分别计算并使用封闭（包裹）盒给障碍物和车
            BoundingBox aHazardBox = new BoundingBox(new Vector3(theHazard.Position.X, theHazard.Position.Y, 0), new Vector3(theHazard.Position.X + (mHazard.Width * .4f), theHazard.Position.Y + ((mHazard.Height - 50) * .4f), 0));
            BoundingBox aCarBox = new BoundingBox(new Vector3(mCarPosition.X, mCarPosition.Y, 0), new Vector3(mCarPosition.X + (mCar[flag2 - 1].Width * .2f), mCarPosition.Y + (mCar[flag2 - 1].Height * .2f), 0));

            if (aHazardBox.Intersects(aCarBox) == true) // 碰上了吗?
            {
                mCurrentState = State.Crash;
                mCarsRemaining -= 1;
                soundbank.PlayCue("192");
                if (mCarsRemaining < 0)
                {
                    mCurrentState = State.GameOver;
                    mExitCountDown = 10;
                }
                return true;
            }

            return false;
        }
        private bool CheckCollision2(Hazard theHazard)
        {
            // 分别计算并使用封闭（包裹）盒给障碍物和车
            BoundingBox aHazardBox = new BoundingBox(new Vector3(theHazard.Position.X, theHazard.Position.Y, 0), new Vector3(theHazard.Position.X + (mCar2.Width * .2f), theHazard.Position.Y + ((mCar2.Height - 50) * .2f), 0));
            BoundingBox aCarBox = new BoundingBox(new Vector3(mCarPosition.X, mCarPosition.Y, 0), new Vector3(mCarPosition.X + (mCar[flag2 - 1].Width * .2f), mCarPosition.Y + (mCar[flag2 - 1].Height * .2f), 0));

            if (aHazardBox.Intersects(aCarBox) == true) // 碰上了吗?
            {
                mCurrentState = State.Crash;
                mCarsRemaining -= 1;
                soundbank.PlayCue("192");
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
                        DrawText("Welcome to the game", 100);
                        DrawTextCentered("Running", 200, flag == 1,Color.Blue);
                        DrawTextCentered("Option", 250, flag == 2, Color.Blue);
                       
                        DrawTextCentered("Choose Car", 300, flag == 3, Color.Blue);
                        DrawTextCentered("Exit", 400, flag == 5, Color.Blue);
                        DrawTextCentered("Difficultity", 350, flag == 4, Color.Blue);
                        DrawText("Exit in " + ((int)mExitCountDown).ToString(), 475);

                        break;
                    }

                case State.Option:
                    {

                        DrawTextCentered("Full Screen", 200, flag1 == 1, Color.Blue);
                        DrawTextCentered("Back To Title", 250, flag1 == 2, Color.Blue);
                        //DrawTextCentered("Difficultity", 300, flag1 == 3, Color.Blue);
                       
                        break;
                    }

                case State.ChooseCar:
                    {

                        DrawTextCentered("Car1", 200, flag2 == 1, Color.Blue);
                        DrawTextCentered("Car2", 250, flag2 == 2, Color.Blue);
                        DrawTextCentered("Car3", 300, flag2 == 3, Color.Blue);

                        break;
                    }
                case State.Diff:
                    {

                        DrawTextCentered("Easy", 200, flag3 == 1, Color.Blue);
                        DrawTextCentered("Simple", 250, flag3 == 2, Color.Blue);
                        DrawTextCentered("Hard", 300, flag3 == 3, Color.Blue);

                        break;
                    }
                default:
                    {
                        DrawRoad();
                        DrawHazards();
                        DrawHazards2();
                        spriteBatch.Draw(mCar[flag2 - 1], mCarPosition, new Rectangle(0, 0, mCar[flag2 - 1].Width, mCar[flag2 - 1].Height), Color.White, 0, new Vector2(0, 0), 0.2f, SpriteEffects.None, 0);

                        spriteBatch.DrawString(mFont, "Cars:", new Vector2(28, 520), Color.Brown, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);
                        for (int aCounter = 0; aCounter < mCarsRemaining; aCounter++)
                        {
                            spriteBatch.Draw(mCar[flag2 - 1], new Vector2(25 + (30 * aCounter), 550), new Rectangle(0, 0, mCar[flag2 - 1].Width, mCar[flag2 - 1].Height), Color.White, 0, new Vector2(0, 0), 0.05f, SpriteEffects.None, 0);
                        }

                        spriteBatch.DrawString(mFont, "Hazards: " + mHazardsPassed.ToString(), new Vector2(5, 25), Color.Brown, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);

                        if (mCurrentState == State.Crash)
                        {
                            DrawTextDisplayArea();

                            DrawText("Crash!", 200);
                            DrawText("Press 'Space' to continue driving.", 260);
                        }
                        else if (mCurrentState == State.GameOver)
                        {
                            DrawTextDisplayArea();
                            DrawText("Game Over.", 200);
                            DrawText("Press 'Space' to try again.", 260);
                            DrawText("Exit in " + ((int)mExitCountDown).ToString(), 400);

                        }
                        else if (mCurrentState == State.Success)
                        {
                            DrawTextDisplayArea();
                            DrawText("Congratulations!", 200);
                            DrawText("Press 'Space' to play again.", 260);
                            DrawText("Exit in " + ((int)mExitCountDown).ToString(), 400);
                        }

                        break;
                    }
            }
            spriteBatch.End();

            base.Draw(gameTime);
        }

        private void DrawText(string theDisplayText, int thePositionY)
        {
            Vector2 aSize = mFont.MeasureString(theDisplayText);
            int aPositionX = (int)((graphics.GraphicsDevice.Viewport.Width / 2) - (aSize.X / 2));
          
            
                spriteBatch.DrawString(mFont, theDisplayText, new Vector2(aPositionX, thePositionY), Color.Beige, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);
                spriteBatch.DrawString(mFont, theDisplayText, new Vector2(aPositionX + 1, thePositionY + 1), Color.Brown, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);
            
        }

        private void DrawRoad()
        {
            for (int aIndex = 0; aIndex < mRoadY.Length; aIndex++)
            {
                if (mRoadY[aIndex] > mRoad.Height * -1 && mRoadY[aIndex] <= this.Window.ClientBounds.Height)
                {
                        spriteBatch.Draw(mRoad, new Rectangle((int)((this.Window.ClientBounds.Width - mRoad.Width) / 2), mRoadY[aIndex], mRoad.Width, mRoad.Height + 5), Color.White);
                }
            }
        }

        private void DrawHazards()
        {
           
            foreach (Hazard aHazard in mHazards)
            {
                
                    if (aHazard.Visible == true)
                    {
                        spriteBatch.Draw(mHazard, aHazard.Position, new Rectangle(0, 0, mHazard.Width, mHazard.Height), Color.White, 0, new Vector2(0, 0), 0.4f, SpriteEffects.None, 0);
                    }
                    
                
            }
        }
        private void DrawHazards2()
        {

            foreach (Hazard aHazard in mHazards2)
            {

                if (aHazard.Visible == true)
                {
                    spriteBatch.Draw(mCar2, aHazard.Position, new Rectangle(0, 0, mCar2.Width, mCar2.Height), Color.White, 0, new Vector2(0, 0), 0.2f, SpriteEffects.None, 0);
                }


            }
        }

        private void DrawTextDisplayArea()
        {
            int aPositionX = (int)((graphics.GraphicsDevice.Viewport.Width / 2) - (450 / 2));
            spriteBatch.Draw(mBackground, new Rectangle(aPositionX-20, 75, 480, 400), Color.White);
        }

        private void DrawTextCentered(string theDisplayText, int thePositionY, bool cho,Color col)
        {

            Vector2 aSize = mFont.MeasureString(theDisplayText);
            int aPositionX = (int)((graphics.GraphicsDevice.Viewport.Width / 2) - (aSize.X / 2));
            if (cho == true)
            {
                spriteBatch.DrawString(mFont, theDisplayText, new Vector2(aPositionX, thePositionY), col, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);
            }
                spriteBatch.DrawString(mFont, theDisplayText, new Vector2(aPositionX + 1, thePositionY + 1), Color.Brown, 0, new Vector2(0, 0), 1.0f, SpriteEffects.None, 0);
           
        }
    }
}
