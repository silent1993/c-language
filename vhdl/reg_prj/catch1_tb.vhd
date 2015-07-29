--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:35:53 05/22/2014
-- Design Name:   
-- Module Name:   I:/vhdl/reg_prj/catch1_tb.vhd
-- Project Name:  reg_prj
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: catche1
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
use IEEE.STD_LOGIC_ARITH.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY catch1_tb IS
END catch1_tb;
 
ARCHITECTURE behavior OF catch1_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT catche1
    PORT(
	 A: in STD_LOGIC_VECTOR ( 9 downto 0);
	CS : in STD_LOGIC;
	WE : in STD_LOGIC;
	DIO: inout STD_LOGIC_VECTOR (3 downto 0) );
    END COMPONENT;
    
	signal A : std_logic_vector(9 downto 0) := (others => '0');
   signal DIO: std_logic_vector(3 downto 0) := (others => '0');
   signal CS : std_logic := '0';
   signal WE : std_logic := '0';
	 
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   --constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: catche1 PORT MAP (
			A=>A,
			WE=>WE,
			CS=>CS,
			DIO=>DIO
        );

   -- Clock process definitions
   --<clock>_process :process
   --begin
		--<clock> <= '0';
		--wait for <clock>_period/2;
		--<clock> <= '1';
		---wait for <clock>_period/2;
   --end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      --wait for <clock>_period*10;
		A<="1111100000";
		CS<='0';
		WE<='0';
		DIO<="1111";
		
		wait for 100 ns;
		
		A<="1111100000";
		CS<='1';
		WE<='0';
		DIO<="0000";
		
		wait for 100 ns;
		
		A<="1111100001";
		CS<='0';
		WE<='1';
		DIO<="0011";
		
		wait for 100 ns;
		
		A<="1111100001";
		CS<='1';
		WE<='0';
		DIO<="0000";

      -- insert stimulus here 

      wait;
   end process;

END;
