--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:57:27 07/09/2014
-- Design Name:   
-- Module Name:   D:/vhdl/cpu/alu_tb.vhd
-- Project Name:  cpu
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
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY alu_tb IS
END alu_tb;
 
ARCHITECTURE behavior OF alu_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu
    PORT(
         CS1 : IN  std_logic;
         Raddr : IN  std_logic_vector(2 downto 0);
         Rupdate : IN  std_logic;
         Rdata : IN  std_logic_vector(7 downto 0);
         IR : IN  std_logic_vector(15 downto 0);
         OP : OUT  std_logic_vector(4 downto 0);
         ALUOUT : OUT  std_logic_vector(7 downto 0);
         ADDR : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CS1 : std_logic := '0';
   signal Raddr : std_logic_vector(2 downto 0) := (others => '0');
   signal Rupdate : std_logic := '0';
   signal Rdata : std_logic_vector(7 downto 0) := (others => '0');
   signal IR : std_logic_vector(15 downto 0) := (others => '0');

 	--Outputs
   signal OP : std_logic_vector(4 downto 0);
   signal ALUOUT : std_logic_vector(7 downto 0);
   signal ADDR : std_logic_vector(15 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu PORT MAP (
          CS1 => CS1,
          Raddr => Raddr,
          Rupdate => Rupdate,
          Rdata => Rdata,
          IR => IR,
          OP => OP,
          ALUOUT => ALUOUT,
          ADDR => ADDR
        );

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;
			CS1 <='1';
		Rupdate<='1';
		Raddr<="000";
		Rdata<="00000000";
		wait for 10 ns;
		Rupdate<='1';
		Raddr<="001";
		Rdata<="00000001";
		wait for 10 ns;
		Rupdate<='1';
		Raddr<="010";
		Rdata<="00000010";
		wait for 10 ns;
		Rupdate<='1';
		Raddr<="011";
		Rdata<="00000011";
		wait for 10 ns;
		Rupdate<='1';
		Raddr<="100";
		Rdata<="00000100";
		wait for 10 ns;
		Rupdate<='1';
		Raddr<="101";
		Rdata<="00000101";
		wait for 10 ns;
		Rupdate<='1';
		Raddr<="110";
		Rdata<="00000110";
		wait for 10 ns;
		Rupdate<='1';
		Raddr<="111";
		Rdata<="00000111";
		wait for 10 ns;
			Rupdate<='0';
		
         IR <="0000100100000011"	;--jz
			  wait for 10 ns;
			CS1 <='1';
         IR <="0001100000000011"	;--jmp
				  wait for 10 ns;
			CS1 <='1';
         IR <="0100001100000101"	;--sub

	  wait for 10 ns;
			CS1 <='1';
         IR <="0101000000000101"	;--add
			wait for 10 ns;
			CS1 <='1';
         IR <="0110101100000101"	;--mvi
			wait for 10 ns;
			CS1 <='1';
         IR <="0111010000000101"	;--mov
			wait for 10 ns;
			CS1 <='1';
         IR <="1000111000000101"	;--STA
			wait for 10 ns;
			CS1 <='1';
         IR <="1001110100000101"	;--LDA
			wait for 10 ns;
			CS1 <='1';
         IR <="1101010100000101"	;--out
			wait for 10 ns;
			CS1 <='1';
         IR <="1100010100000101"	;--IN


      -- insert stimulus here 

      wait;
   end process;

END;
