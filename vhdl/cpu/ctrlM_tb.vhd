--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:56:30 07/11/2014
-- Design Name:   
-- Module Name:   D:/vhdl/cpu/ctrlM_tb.vhd
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
 
ENTITY ctrlM_tb IS
END ctrlM_tb;
 
ARCHITECTURE behavior OF ctrlM_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ctrl_M
    PORT(
         PC : IN  std_logic_vector(15 downto 0);
         ADDR : IN  std_logic_vector(15 downto 0);
         OP : IN  std_logic_vector(4 downto 0);
         datain : IN  std_logic_vector(7 downto 0);
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
