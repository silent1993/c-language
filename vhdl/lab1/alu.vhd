----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:58:45 07/01/2014 
-- Design Name: 
-- Module Name:    foue_two - Behavioral 
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.std_logic_unsigned.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity foue_two is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           t1:out STD_LOGIC;
			  t2:out STD_LOGIC;
			  t3:out STD_LOGIC;
			  t4:out STD_LOGIC);
end foue_two;

architecture Behavioral of foue_two is
shared variable tem:integer;

begin
process(clk,reset)
begin

	t1<='0';
t2<='0';
t3<='0';
t4<='0';

	if(reset='1')then
		tem:=0;
	elsif(clk'event and clk='1') then
		tem:=tem+1;
	end if;
	if(tem=0) then
		t1<='1';
	elsif(tem=1) then
		t2<='1';
	elsif(tem=2) then
		t3<='1';
	elsif(tem=3) then
		t4<='1';
		tem:=0;
	else
		tem:=0;
	end if;
	
end process;

end Behavioral;
