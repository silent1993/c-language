--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:58:22 07/11/2014
-- Design Name:   
-- Module Name:   D:/vhdl/cpu/ctr_M_tb.vhd
-- Project Name:  cpu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ctrl_M
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
 
ENTITY ctr_M_tb IS
END ctr_M_tb;
 
ARCHITECTURE behavior OF ctr_M_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ctrl_M
    PORT(
         PC : IN  std_logic_vector(15 downto 0);
         ADDR : IN  std_logic_vector(15 downto 0);
         OP : IN  std_logic_vector(4 downto 0);
         datain : IN  std_logic_vector(7 downto 0);
         CS0 : IN  std_logic;
         CS2 : IN  std_logic;
         MADDR : OUT  std_logic_vector(7 downto 0);
         MPC : OUT  std_logic_vector(15 downto 0);
         DBUS : INOUT  std_logic_vector(15 downto 0);
         ABUS : OUT  std_logic_vector(15 downto 0);
         nMREQ : OUT  std_logic;
         nRD : OUT  std_logic;
         nWR : OUT  std_logic;
         nBHE : OUT  std_logic;
         nBLE : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal PC : std_logic_vector(15 downto 0) := (others => '0');
   signal ADDR : std_logic_vector(15 downto 0) := (others => '0');
   signal OP : std_logic_vector(4 downto 0) := (others => '0');
   signal datain : std_logic_vector(7 downto 0) := (others => '0');
   signal CS0 : std_logic := '0';
   signal CS2 : std_logic := '0';

	--BiDirs
   signal DBUS : std_logic_vector(15 downto 0);

 	--Outputs
   signal MADDR : std_logic_vector(7 downto 0);
   signal MPC : std_logic_vector(15 downto 0);
   signal ABUS : std_logic_vector(15 downto 0);
   signal nMREQ : std_logic;
   signal nRD : std_logic;
   signal nWR : std_logic;
   signal nBHE : std_logic;
   signal nBLE : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ctrl_M PORT MAP (
          PC => PC,
          ADDR => ADDR,
          OP => OP,
          datain => datain,
          CS0 => CS0,
          CS2 => CS2,
          MADDR => MADDR,
          MPC => MPC,
          DBUS => DBUS,
          ABUS => ABUS,
          nMREQ => nMREQ,
          nRD => nRD,
          nWR => nWR,
          nBHE => nBHE,
          nBLE => nBLE
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;
	 DBUS<="ZZZZZZZZZZZZZZZZ";
		wait for 100 ns;
		CS0<='1';
		 PC<="0000011111000000";
		 DBUS<="0101010101010101";
		 wait for 50 ns;
		 CS0<='0';
		 CS2<='1';
		 DBUS<="ZZZZZZZZZZZZZZZZ";
		 OP<="10001";
		 datain<="10101010";
		 Addr<="1100000101000100";
		  wait for 50 ns;
		  CS2<='1';
		  DBUS<="1010101010101010";
		 OP<="10011";
		 Addr<="1100000101000101";

      -- insert stimulus here 

      wait;
   end process;

END;
