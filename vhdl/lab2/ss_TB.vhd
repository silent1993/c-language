--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   08:24:06 06/27/2014
-- Design Name:   
-- Module Name:   D:/vhdl/lab2/ss_TB.vhd
-- Project Name:  lab2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ss
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
 
ENTITY ss_TB IS
END ss_TB;
 
ARCHITECTURE behavior OF ss_TB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ss
    PORT(
         DI : IN  std_logic;
         DO : OUT  std_logic;
         CLK : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal DI : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal DO : std_logic;

   -- Clock period definitions
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ss PORT MAP (
          DI => DI,
          DO => DO,
          CLK => CLK
        );

   -- Clock process definitions
   
 

   -- Stimulus process
  stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 50 ns;	
		DI<='1';
		CLK<='1';
      wait for 50  ns;
		DI<='1';
		CLK<='0';
		wait for 50 ns;
		DI<='0';
		CLK<='1';
		wait for 50 ns;
		DI<='0';
		CLK<='0';
		wait for 50 ns;
		DI<='0';
		CLK<='1';
		wait for 50 ns;
		DI<='0';
		CLK<='0';
		wait for 50 ns;
		DI<='1';
		CLK<='1';
     	wait for 50 ns;
		DI<='1';
		CLK<='0';
		wait for 50 ns;
		DI<='1';
		CLK<='1';
		wait for 50 ns;
		DI<='1';
		CLK<='0';
		wait for 50 ns;
		DI<='1';
		CLK<='1';
		wait for 50 ns;
		DI<='1';
		CLK<='0';
		wait for 50 ns;
		DI<='1';
		CLK<='1';
		wait for 50 ns;
		DI<='1';
		CLK<='0';
		wait for 50 ns;
		DI<='1';
		CLK<='1';
		wait for 50 ns;
		DI<='1';
		CLK<='0';
		wait for 50 ns;
		DI<='1';
		CLK<='1';
      -- insert stimulus here 

      wait;
   end process;

END;
