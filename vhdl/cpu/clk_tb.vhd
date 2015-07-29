--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:07:12 07/09/2014
-- Design Name:   
-- Module Name:   D:/vhdl/cpu/clk_tb.vhd
-- Project Name:  cpu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: number1
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
 
ENTITY clk_tb IS
END clk_tb;
 
ARCHITECTURE behavior OF clk_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT number1
    PORT(
         CLK : IN  std_logic;
         RST : IN  std_logic;
			
         T1 : OUT  std_logic;
         T2 : OUT  std_logic;
         T3 : OUT  std_logic;
         T4 : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RST : std_logic := '0';

 	--Outputs
   signal T1 : std_logic;
   signal T2 : std_logic;
   signal T3 : std_logic;
   signal T4 : std_logic;
   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: number1 PORT MAP (
          CLK => CLK,
          RST => RST,
			
          T1 => T1,
          T2 => T2,
          T3 => T3,
          T4 => T4
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		

      wait for CLK_period;
		rst<='1';
		
      wait for CLK_period;
		rst<='0';

      -- insert stimulus here 

      wait;
   end process;

END;
