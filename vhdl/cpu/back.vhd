----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:46:10 07/08/2014 
-- Design Name: 
-- Module Name:    back - Behavioral 
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
use ieee.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity back is
    Port ( CS3 : in  STD_LOGIC;
           PC : in  STD_LOGIC_VECTOR (15 downto 0);
           IR : in  STD_LOGIC_VECTOR (15 downto 0);
				adir:in STD_LOGIC_VECTOR (15 downto 0);
			  Rtemp:in  STD_LOGIC_VECTOR (7 downto 0);
			  Atemp:in  STD_LOGIC_VECTOR (7 downto 0);
           ALUOUT : in  STD_LOGIC_VECTOR (7 downto 0);
           PCupdate : out  STD_LOGIC;
           PCnew : out  STD_LOGIC_VECTOR (15 downto 0);
           Rupdate : out  STD_LOGIC;
           Raddr : out  STD_LOGIC_VECTOR (2 downto 0);
           Rdata : out  STD_LOGIC_VECTOR (7 downto 0));
end back;

architecture Behavioral of back is
begin
process(CS3,PC,IR,ALUOUT)

begin
if(CS3='1')then
PCupdate<='1';
	case IR(15 downto 14) is
	when "00"=>
		if(IR(12)='1')then
			PCnew<=PC+ADiR;
			else
			if(Atemp="00000000")then
				PCnew<=PC+ADiR;
			else
				PCnew<=PC+"0000000000000001";
			end if;
		end if;
	when "01"=>
			PCnew<=PC+"0000000000000001";
		Rupdate<='1';
		Raddr<=IR(10 downto 8);
		Rdata<=ALUOUT;
	when "10"=>
				PCnew<=PC+"0000000000000001";
		if(IR(12)='1')then
			Rupdate<='1';
		Raddr<=IR(10 downto 8);
		Rdata<=Rtemp;
		end if;
		when "11"=>
		PCnew<=PC+"0000000000000001";
		if(IR(12)='0')then
			Rupdate<='1';
		Raddr<=IR(10 downto 8);
		Rdata<=Rtemp;
		end if;
		when others=>NULL;
end case;
end if;

end process;


end Behavioral;

