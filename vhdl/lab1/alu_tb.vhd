--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   06:29:48 06/25/2014
-- Design Name:   
-- Module Name:   I:/vhdl/lab1/alu_tb.vhd
-- Project Name:  lab1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: alu
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
use IEEE.std_logic_unsigned.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY alu_tb IS
END alu_tb;
 
ARCHITECTURE behavior OF alu_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu
    PORT(
         A : IN  std_logic_vector(7 downto 0);
         B : IN  std_logic_vector(7 downto 0);
         Cin : IN  std_logic;
         Card : IN  std_logic_vector(4 downto 0);
         F : OUT  std_logic_vector(7 downto 0);
         Cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(7 downto 0) := (others => '0');
   signal B : std_logic_vector(7 downto 0) := (others => '0');
   signal Cin : std_logic := '0';
   signal Card : std_logic_vector(4 downto 0) := (others => '0');

 	--Outputs
   signal F : std_logic_vector(7 downto 0);
   signal Cout : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
  
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu PORT MAP (
          A => A,
          B => B,
          Cin => Cin,
          Card => Card,
          F => F,
          Cout => Cout
        );

  
 

   -- Stimulus process
   stim_proc: process
   begin		
	wait for 50 ns;
      -- hold reset state for 100 ns.
		
      A<="10101110";
		B<="11001110";
		Cin<='1';
		Card<="00001";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='1';
		Card<="00010";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='1';
		Card<="00011";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='1';
		Card<="00100";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='1';
		Card<="00101";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='1';
		Card<="00110";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="00111";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="01000";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="01001";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="01010";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="01011";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="01100";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="01101";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="01110";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="01111";
		wait for 50 ns;
		 A<="10101110";
		B<="11001110";
		Cin<='0';
		Card<="10000";
		wait for 50 ns;
		 A<="10101111";
		B<="11001110";
		Cin<='1';
		Card<="00001";
		wait for 50 ns;
		 A<="10101111";
		B<="11001110";
		Cin<='1';
		Card<="01011";

      -- insert stimulus here 

      wait;
   end process;

END;
