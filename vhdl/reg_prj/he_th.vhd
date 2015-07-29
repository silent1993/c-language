--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   19:37:11 05/19/2014
-- Design Name:   
-- Module Name:   I:/vhdl/reg_prj/he_th.vhd
-- Project Name:  reg_prj
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: he_vh
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
 
ENTITY he_th IS
END he_th;
 
ARCHITECTURE behavior OF he_th IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT he_vh
    PORT(
         cs : IN  std_logic;
         wr : IN  std_logic;
         rd : IN  std_logic;
         data_i : IN  std_logic_vector(3 downto 0);
         data_o : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

 


   --Inputs
   signal cs : std_logic := '0';
   signal rd : std_logic := '0';
   signal wr : std_logic := '0';
   signal data_i : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal data_o : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: he_vh PORT MAP (
          cs => cs,
          rd => rd,
          wr => wr,
          data_i => data_i,
          data_o => data_o
        );

   

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		cs <= '1';
		wr <= '1';
		rd <= '0';
		data_i <= "1010";
		
		wait for 100 ns;	
		cs <= '1';
		wr <= '0';
		rd <= '1';
		data_i <= "0000";
		
		wait for 100 ns;	
		cs <= '1';
		wr <= '1';
		rd <= '0';
		data_i <= "1111";
		
		wait for 100 ns;	
		cs <= '1';
		wr <= '0';
		rd <= '1';
		data_i <= "0000";

      wait;
   end process;

END;
