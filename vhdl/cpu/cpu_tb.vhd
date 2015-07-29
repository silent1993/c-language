--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:57:41 07/12/2014
-- Design Name:   
-- Module Name:   D:/vhdl/cpu/cpu_tb.vhd
-- Project Name:  cpu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: CPU
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY cpu_tb IS
END cpu_tb;
 
ARCHITECTURE behavior OF cpu_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT CPU
    PORT(
         RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           ABUS : out  STD_LOGIC_VECTOR (15 downto 0);
           DBUS : inout  STD_LOGIC_VECTOR (15 downto 0);
           nMREQ : out  STD_LOGIC;
           nRD : out  STD_LOGIC;
           nWR : out  STD_LOGIC;
           nBHE : out  STD_LOGIC;
           nBLE : out  STD_LOGIC;
           IODB : inout  STD_LOGIC_VECTOR (7 downto 0);
			  nPREQ : out  STD_LOGIC;
           nPRD : out  STD_LOGIC;
           nPWR : out  STD_LOGIC
        );
    END COMPONENT;
    

   --Inputs
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';
	--BiDirs
   signal DBUS : std_logic_vector(15 downto 0):=(others=>'Z');
    signal IODB: std_logic_vector(7 downto 0):=(others=>'Z');

 	--Outputs
	signal  ABUS : STD_LOGIC_VECTOR (15 downto 0);
		signal nMREQ :   STD_LOGIC;
        signal    nRD :STD_LOGIC;
        signal    nWR :  STD_LOGIC;
      signal      nBHE :   STD_LOGIC;
       signal     nBLE :  STD_LOGIC;
		 signal 	  nPREQ :  STD_LOGIC;
      signal      nPRD :   STD_LOGIC;
       signal     nPWR :  STD_LOGIC;
   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: CPU PORT MAP (
          RST => RST,
          CLK => CLK,
          ABUS => ABUS,
          DBUS => DBUS,
          nMREQ => nMREQ,
          nRD => nRD,
          nWR => nWR,
          nBHE => nBHE,
          nBLE => nBLE,
          IODB => IODB,
          nPREQ => nPREQ,
          nPRD => nPRD,
          nPWR => nPWR
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '1';
		wait for CLK_period/2;
		CLK <= '0';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
	--	rst<='1';
		wait for CLK_period;
		RST <='1';
		
--mvi r7=00011111
		wait for CLK_period;
		RST<='0';
		DBUS<="0110111100011111";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
--mvi r1=00011100
		wait for CLK_period;
		DBUS<="0110100100011100";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
--mvi r0=00000001
		wait for CLK_period;
		DBUS<="0110100000000001";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
--JZ 
		wait for CLK_period;
		DBUS<="0000100000011100";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		
--mvi r0=00000000
		wait for CLK_period;
		DBUS<="0110100000000000";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
--JZ 
		wait for CLK_period;
		DBUS<="0000100000011100";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
--JMP
		wait for CLK_period;
		DBUS<="0001100000000011";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";

--mov r7->r2
		wait for CLK_period;
		DBUS<="0111001000011111";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
--add 
		wait for CLK_period;
		DBUS<="0101000100011111";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		
--sub
		wait for CLK_period;
		DBUS<="0100001000011111";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		--DBUS<="ZZZZZZZZZZZZZZZZ";
--out r1
		wait for CLK_period;
		 DBUS<="1101000100011110";
		wait for CLK_period;		
		
		wait for CLK_period;
		
		wait for CLK_period;
		
--out r2
		wait for CLK_period;
		 DBUS<="1101001000011110";
		wait for CLK_period;		
		
		wait for CLK_period;
		
		wait for CLK_period;
 --STA
	  wait for CLK_period;
		 DBUS<="1000111100011111";
		wait for CLK_period;
	   DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		DBUS<="ZZZZZZZZZZZZZZZZ";
      --insert stimulus here 
		
		
	--LDA 100=111
	  wait for CLK_period;
		 DBUS<="1001110000011110";
		wait for CLK_period;
	   DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for CLK_period;
		DBUS<="ZZZZZZZZ00011111";
		wait for CLK_period;
		DBUS<="ZZZZZZZZZZZZZZZZ";
--out   
		wait for CLK_period;
		 DBUS<="1101010000011110";
		wait for CLK_period;		
		IODB<="ZZZZZZZZ";
		wait for CLK_period;
		IODB<="ZZZZZZZZ";
		wait for CLK_period;
		IODB<="ZZZZZZZZ";
--in 110=00001111
		wait for CLK_period;
		 DBUS<="1100011000001111";
		wait for CLK_period;		

		wait for CLK_period;
		IODB<="00001111";
		wait for CLK_period;

--out   
		wait for CLK_period;
		 DBUS<="1101011000011110";
		wait for CLK_period;		

		wait for CLK_period;
		IODB<="ZZZZZZZZ";
		wait for CLK_period;

      wait;
   end process;

END;
