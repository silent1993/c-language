--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:01:34 06/27/2014
-- Design Name:   
-- Module Name:   D:/vhdl/lad3/state_TB.vhd
-- Project Name:  lad3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: state
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
 
ENTITY state_TB IS
END state_TB;
 
ARCHITECTURE behavior OF state_TB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT state
    PORT(
         read_write : IN  std_logic;
         ready : IN  std_logic;
         clk : IN  std_logic;
         oe : OUT  std_logic;
         we : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal read_write : std_logic := '0';
   signal ready : std_logic := '0';
   signal clk : std_logic := '0';

 	--Outputs
   signal oe : std_logic;
   signal we : std_logic;

   -- Clock period definitions
  
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: state PORT MAP (
          read_write => read_write,
          ready => ready,
          clk => clk,
          oe => oe,
          we => we
        );

   -- Clock process definitions
   
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 50 ns;	
		clk<='1';
		read_write<='1';
		ready<='1';
		 wait for 50 ns;	
		clk<='0';
		read_write<='1';
		ready<='1';
		 wait for 50 ns;	
		clk<='1';
		read_write<='1';
		ready<='1';
		 wait for 50 ns;	
		clk<='0';
		read_write<='1';
		ready<='1';
		wait for 50 ns;	
		clk<='1';
		read_write<='1';
		ready<='0';
		wait for 50 ns;	
		clk<='0';
		read_write<='1';
		ready<='0';
		wait for 50 ns;	
		clk<='1';
		read_write<='1';
		ready<='0';
			wait for 50 ns;	
		clk<='0';
		read_write<='0';
		ready<='0';
			wait for 50 ns;	
		clk<='1';
		read_write<='0';
		ready<='1';
			wait for 50 ns;	
		clk<='0';
		read_write<='0';
		ready<='1';
		wait for 50 ns;	
		clk<='1';
		read_write<='0';
		ready<='0';
			wait for 50 ns;	
		clk<='0';
		read_write<='0';
		ready<='0';
		wait for 50 ns;	
		clk<='1';
		read_write<='0';
		ready<='0';
		wait for 50 ns;	
		clk<='0';
		read_write<='0';
		ready<='0';


    
      -- insert stimulus here 

      wait;
   end process;

END;
