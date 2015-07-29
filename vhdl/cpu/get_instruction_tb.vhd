--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:26:09 07/09/2014
-- Design Name:   
-- Module Name:   D:/vhdl/cpu/get_instruction_tb.vhd
-- Project Name:  cpu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: quzhi
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
 
ENTITY get_instruction_tb IS
END get_instruction_tb;
 
ARCHITECTURE behavior OF get_instruction_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT quzhi
    PORT(
         PCupdate : IN  std_logic;
         PCnew : IN  std_logic_vector(15 downto 0);
         CS0 : IN  std_logic;
         RST : IN  std_logic;
         MPC : IN  std_logic_vector(15 downto 0);
         IR : OUT  std_logic_vector(15 downto 0);
         PC : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal PCupdate : std_logic := '0';
   signal PCnew : std_logic_vector(15 downto 0) := (others => '0');
   signal CS0 : std_logic := '0';
   signal RST : std_logic := '0';
   signal MPC : std_logic_vector(15 downto 0) := (others => '0');

 	--Outputs
   signal IR : std_logic_vector(15 downto 0);
   signal PC : std_logic_vector(15 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: quzhi PORT MAP (
          PCupdate => PCupdate,
          PCnew => PCnew,
          CS0 => CS0,
          RST => RST,
          MPC => MPC,
          IR => IR,
          PC => PC
        );

  

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;
		CS0<='1';
		RST<='1';
		MPC<="0101010101010101";
		 wait for 100 ns;
		CS0<='0';
		RST<='0';
		MPC<="0101010101010110";
		wait for 100 ns;
		CS0<='1';
		RST<='0';
		PCupdate<='1';
		PCnew<="0000000000000001";
		MPC<="0101010101010110";
		wait for 100 ns;
		CS0<='0';
		RST<='0';
		PCnew<="0000000000000010";
		MPC<="0101010101010111";
		wait for 100 ns;
		CS0<='1';
		RST<='1';
		MPC<="0101010101010111";
		wait for 100 ns;
		CS0<='1';
		RST<='0';
		MPC<="0101010101010111";
		PCupdate<='1';
		PCnew<="0000000001111111";

      -- insert stimulus here 

      wait;
   end process;

END;
