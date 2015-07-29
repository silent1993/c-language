--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   20:57:55 07/10/2014
-- Design Name:   
-- Module Name:   D:/vhdl/cpu/back_tb.vhd
-- Project Name:  cpu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: back
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
 
ENTITY back_tb IS
END back_tb;
 
ARCHITECTURE behavior OF back_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT back
    PORT(
         CS3 : IN  std_logic;
         PC : IN  std_logic_vector(15 downto 0);
         IR : IN  std_logic_vector(15 downto 0);
			adir:in STD_LOGIC_VECTOR (15 downto 0);
         Rtemp : IN  std_logic_vector(7 downto 0);
         Atemp : IN  std_logic_vector(7 downto 0);
         ALUOUT : IN  std_logic_vector(7 downto 0);
         PCupdate : OUT  std_logic;
         PCnew : OUT  std_logic_vector(15 downto 0);
         Rupdate : OUT  std_logic;
         Raddr : OUT  std_logic_vector(2 downto 0);
         Rdata : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CS3 : std_logic := '0';
   signal PC : std_logic_vector(15 downto 0) := (others => '0');
   signal IR : std_logic_vector(15 downto 0) := (others => '0');
	signal adir : std_logic_vector(15 downto 0) := (others => '0');
   signal Rtemp : std_logic_vector(7 downto 0) := (others => '0');
   signal Atemp : std_logic_vector(7 downto 0) := (others => '0');
   signal ALUOUT : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal PCupdate : std_logic;
   signal PCnew : std_logic_vector(15 downto 0);
   signal Rupdate : std_logic;
   signal Raddr : std_logic_vector(2 downto 0);
   signal Rdata : std_logic_vector(7 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: back PORT MAP (
          CS3 => CS3,
          PC => PC,
          IR => IR,
			 adir=>adir,
          Rtemp => Rtemp,
          Atemp => Atemp,
          ALUOUT => ALUOUT,
          PCupdate => PCupdate,
          PCnew => PCnew,
          Rupdate => Rupdate,
          Raddr => Raddr,
          Rdata => Rdata
        );


 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 50 ns;	
		CS3 <='1';
      PC <="0000000000000001";
      IR <="0001100000001111";
		adir<="0001100000001111";
		wait for 50 ns;	
		CS3 <='1';
      PC <="0000000000000001";
      IR <="0000100100001111";
		Atemp<="00000000";
			adir<="0001100000001111";
		wait for 50 ns;	
		CS3 <='1';
      --PC <="0000000000000001";
      IR <="0100000100001111";
		ALUOUT<="01010101";
			adir<="0001100000001111";
		wait for 50 ns;	
		CS3 <='1';
      --PC <="0000000000000001";
      IR <="1001100100001111";
		Rtemp<="01010111";
			adir<="0001100000001111";

      wait;
   end process;

END;
