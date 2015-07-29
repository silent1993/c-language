--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:28:19 05/20/2014
-- Design Name:   
-- Module Name:   I:/vhdl/reg_prj/sss.vhd
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
 
ENTITY sss IS
END sss;
 
ARCHITECTURE behavior OF sss IS 
 
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
   signal wr : std_logic := '0';
   signal rd : std_logic := '0';
   signal data_i : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal data_o : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: he_vh PORT MAP (
          cs => cs,
          wr => wr,
          rd => rd,
          data_i => data_i,
          data_o => data_o
        );

   -- Clock process definitions
   <clock>_process :process
   begin
		<clock> <= '0';
		wait for <clock>_period/2;
		<clock> <= '1';
		wait for <clock>_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for <clock>_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
