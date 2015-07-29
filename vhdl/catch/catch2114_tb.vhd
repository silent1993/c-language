--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   08:50:04 05/28/2014
-- Design Name:   
-- Module Name:   I:/vhdl/catch/catch2114_tb.vhd
-- Project Name:  catch
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: catch2114
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
 
ENTITY catch2114_tb IS
END catch2114_tb;
 
ARCHITECTURE behavior OF catch2114_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT catch2114
    PORT(
         A : IN  std_logic_vector(9 downto 0);
         CS : IN  std_logic;
         WE : IN  std_logic;
         DO : OUT  std_logic_vector(3 downto 0);
         DI : IN  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(9 downto 0) := (others => '0');
   signal CS : std_logic := '0';
   signal WE : std_logic := '0';
   signal DI : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal DO : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: catch2114 PORT MAP (
          A => A,
          CS => CS,
          WE => WE,
          DO => DO,
          DI => DI
        );

   -- Clock process definitions
  
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	 
			--input
			A <= "1010101010";
			CS <= '0';
			WE <= '0';
			DI <= "1010";
		wait for 100 ns;
			--stop
			A <= "1010101010";
			CS <= '1';
			WE <= '0';
			DI <= "1010";
		wait for 100 ns;
			--input
			A <= "1111111111";
			CS <= '0';
			WE <= '0';
			DI <= "0101";
		wait for 100 ns;
			--stop
			A <= "1111111111";
			CS <= '1';
			WE <= '0';
			DI <= "0101";
		wait for 100 ns;
			--output
			A <= "1010101010";
			CS <= '0';
			WE <= '1';
			DI <= "1111";
		wait for 100 ns;
			--stop
			A <= "1010101010";
			CS <= '1';
			WE <= '1';
			DI <= "1111";
		wait for 100 ns;
			--output
			A <= "1111111111";
			CS <= '0';
			WE <= '1';
			DI <= "1111";
		wait for 100 ns;
			--stop
			A <= "1111111111";
			CS <= '1';
			WE <= '1';
			DI <= "1111";
		wait for 100 ns;
			--input
			A <= "0101010101";
			CS <= '0';
			WE <= '0';
			DI <= "1111";
		wait for 100 ns;
			--stop
			A <= "0101010101";
			CS <= '1';
			WE <= '0';
			DI <= "1111";
		wait for 100 ns;
			--output
			A <= "0101010101";
			CS <= '0';
			WE <= '1';
			DI <= "0000";
		wait for 100 ns;
			--stop
			A <= "0101010101";
			CS <= '1';
			WE <= '1';
			DI <= "0000";
      wait;
   end process;

END;
