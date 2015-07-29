----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:47:39 07/08/2014 
-- Design Name: 
-- Module Name:    alu - Behavioral 
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

entity alu is
    Port ( CS1 : in  STD_LOGIC;
           Raddr : in  STD_LOGIC_VECTOR (2 downto 0);
           Rupdate : in  STD_LOGIC;
			  Atemp: out STD_LOGIC_VECTOR(7 downto 0);
           Rdata : in  STD_LOGIC_VECTOR (7 downto 0);
           IR : in  STD_LOGIC_VECTOR (15 downto 0);
           OP : out  STD_LOGIC_VECTOR (4 downto 0);
           ALUOUT : out  STD_LOGIC_VECTOR (7 downto 0);
           ADDR : out  STD_LOGIC_VECTOR (15 downto 0));
end alu;

architecture Behavioral of alu is
type mem is array(7 downto 0)of STD_LOGIC_VECTOR(7 downto 0);
signal reg:mem;

begin


process(IR,CS1,Raddr,Rupdate,Rdata)
	variable ad1,ad2:integer;
	variable At,Btemp:STD_LOGIC_VECTOR(7 downto 0);
	variable num:integer;
begin	
if(Rupdate='1')then
		num:=conv_integer(Raddr);
		reg(num)<=Rdata;
		end if;
if(CS1='1')then


	OP<=IR(15 downto 11);
	if(IR(11)='1')then
		ADDR(15 downto 8)<=reg(7);
		ADDR(7 downto 0)<=IR(7 downto 0);
		ad1:=conv_integer(IR(10 downto 8));
		Atemp<=reg(ad1);
		AT:=reg(ad1);
	else
		ad1:=conv_integer(IR(10 downto 8));
		ad2:=conv_integer(IR(2 downto 0));
		Atemp<=reg(ad1);
		At:=reg(ad1);
		Btemp:=reg(ad2);
	end if;
	case IR(15 downto 14) is
	when "00"=>
	if(IR(12)='0')then
		ALUOUT<=At;
	end if;
	when "01"=>
	if(IR(13 downto 12)="00")then
		ALUOUT<=At-Btemp;
	elsif(IR(13 downto 12)="01")then
		ALUOUT<=At+Btemp;
	elsif(IR(13 downto 12)="10")then
		ALUOUT<=IR(7 downto 0);
	elsif(IR(13 downto 12)="11")then
		ALUOUT<=Btemp;
	end if;
	when "10"=>
	if(IR(12)='0')then
		ALUOUT<=At;
	end if;
	when "11"=>
	if(IR(12)='1')then
		ALUOUT<=At;
	end if;
	when others=>NULL;
	end case;
end if;

end process;




end Behavioral;

