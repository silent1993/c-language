--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   03:04:27 06/27/2014
-- Design Name:   
-- Module Name:   D:/vhdl/lab2/move_tv.vhd
-- Project Name:  lab2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: move
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
 
ENTITY move_tv IS
END move_tv;
 
ARCHITECTURE behavior OF move_tv IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT move
    PORT(
         A : IN  std_logic;
         CLK : IN  std_logic;
         B : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal B : std_logic;

   -- Clock period definitions
  -- constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: move PORT MAP (
          A => A,
          CLK => CLK,
          B => B
        );

   -- Clock process definitions
 

   -- Stimulus process
   stim_proc: process
   begin		
	
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		A<='1';
		CLK<='1';
      wait for 100 ns;
		A<='1';
		CLK<='0';
		wait for 100 ns;
		A<='1';
		CLK<='1';
		wait for 100 ns;
		A<='1';
		CLK<='0';
		wait for 100 ns;
		A<='1';
		CLK<='1';
		wait for 100 ns;
		A<='1';
		CLK<='0';

      -- insert stimulus here 

      wait;
   end process;

END;
