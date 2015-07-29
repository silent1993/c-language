--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:00:24 07/21/2014
-- Design Name:   
-- Module Name:   D:/vhdl/cpu/VM_tb.vhd
-- Project Name:  cpu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: visit_M
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
 
ENTITY VM_tb IS
END VM_tb;
 
ARCHITECTURE behavior OF VM_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT visit_M
    PORT(
         CS2 : IN  std_logic;
         datain : IN  std_logic_vector(7 downto 0);
         dataout : OUT  std_logic_vector(7 downto 0);
         ALUOUT : IN  std_logic_vector(7 downto 0);
         OP : IN  std_logic_vector(4 downto 0);
         Rtemp : OUT  std_logic_vector(7 downto 0);
         IODB : INOUT  std_logic_vector(7 downto 0);
         nPREQ : OUT  std_logic;
         nPRD : OUT  std_logic;
         nPWR : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CS2 : std_logic := '0';
   signal datain : std_logic_vector(7 downto 0) := (others => '0');
   signal ALUOUT : std_logic_vector(7 downto 0) := (others => '0');
   signal OP : std_logic_vector(4 downto 0) := (others => '0');

	--BiDirs
   signal IODB : std_logic_vector(7 downto 0);

 	--Outputs
   signal dataout : std_logic_vector(7 downto 0);
   signal Rtemp : std_logic_vector(7 downto 0);
   signal nPREQ : std_logic;
   signal nPRD : std_logic;
   signal nPWR : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 

BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: visit_M PORT MAP (
          CS2 => CS2,
          datain => datain,
          dataout => dataout,
          ALUOUT => ALUOUT,
          OP => OP,
          Rtemp => Rtemp,
          IODB => IODB,
          nPREQ => nPREQ,
          nPRD => nPRD,
          nPWR => nPWR
        );

   -- Clock process definitions
   
   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      cs2 <= '1';
      wait for 50 ns;	
			OP<="10001";
		 CS2 <= '1';
		ALUOUT <="00101010";
	 wait for 50 ns;	
			OP<="10001";
		 CS2 <= '1';
		ALUOUT <="00101010";
		 wait for 50 ns;	
		 OP<="10011";
		 CS2 <= '1';

		datain<="00101001";
		 wait for 50 ns;
		OP<="11000";		 
		 CS2 <= '1';
		IODB<="00000111";
		 wait for 50 ns;	
		 OP<="11010";
		 CS2 <= '1';
		datain<="01001010";
		IODB<="ZZZZZZZZ";
      -- insert stimulus here 	

      wait;
   end process;

END;
