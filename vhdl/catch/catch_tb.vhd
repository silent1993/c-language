--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   08:58:33 05/28/2014
-- Design Name:   
-- Module Name:   I:/vhdl/catch/catch_tb.vhd
-- Project Name:  catch
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: catch
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
 
ENTITY catch_tb IS
END catch_tb;
 
ARCHITECTURE behavior OF catch_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT catch
    PORT(
         A : IN  std_logic_vector(9 downto 0);
         DIO : INOUT  std_logic_vector(3 downto 0);
			CS : IN  std_logic;
         WE : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(9 downto 0) := (others => '0');

	--BiDirs
   signal DOU : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: catch PORT MAP (
          A => A,
          DOU => DOU
        );

   -- Clock process definitions

		
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
--chushihua
      A<="1111100000";
		wait for 100 ns;
   

      -- insert stimulus here 

      wait;
   end process;

END;
