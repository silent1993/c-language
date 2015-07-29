----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:50:03 05/22/2014 
-- Design Name: 
-- Module Name:    catch2114 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity catch2114 is
	port( 
	A: in STD_LOGIC_VECTOR ( 9 downto 0);
	CS : in STD_LOGIC;
	WE : in STD_LOGIC;
	DO: out STD_LOGIC_VECTOR (3 downto 0);
	DI:in STD_LOGIC_VECTOR (3 downto 0));
end catch2114;

architecture Behavioral of catch2114 is
type mem is array (63 downto 0) of STD_LOGIC_VECTOR(63 downto 0);
	signal  sram : mem;
begin
C1 : process(A,DI,CS,WE)
	variable i: integer :=0;
	variable j: integer :=0;
	variable row: integer ;
	variable col:integer  ;
	variable tempr:integer :=1 ;
	variable tempc:integer :=1 ;
	begin
		row:=0;
		col:=0;
		l3:for i in 8 downto 3 loop
			if A(i)='1' then
				row:=row+tempr;
			end if;
			tempr:=tempr*2;
		end loop l3;
		l4:for i in 2 downto 0 loop
			if A(i)='1' then
				col:=col+tempc;
			end if;
			tempc:=tempc*2;
		end loop l4;
		if A(9)='1' then
				col:=col+8;
		end if;
		if cs = '0' then
			--read--
			if we = '1' then 
				DO(3)<=sram(row)(col+16*3);
				DO(2)<=sram(row)(col+16*2);
				DO(1)<=sram(row)(col+16);
				DO(0)<=sram(row)(col);
			--write
			elsif we='0' then
				sram(row)(col+16*3)<=DI(3);
				sram(row)(col+16*2)<=DI(2);
				sram(row)(col+16*1)<=DI(1);
				sram(row)(col)<=DI(0);
			end if;
		elsif cs = '1' then
			DO<="0000";
		end if;
	end process;


end Behavioral;

