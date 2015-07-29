----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:21:35 07/02/2014 
-- Design Name: 
-- Module Name:    count4 - Behavioral 
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
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity count4 is
port(
	clk : in std_logic;
	clrn : in std_logic;
	q : out std_logic_vector(3 downto 0)
	);
end count4 ;

architecture main of count4 is
begin
	process( clk, clrn )
	variable num : integer;
	begin
		if clrn = '0' then
			q <= "0000";
			num := 0;
		elsif clk = '0' and clk'event then
			num := num + 1;
			q <= conv_std_logic_vector(num, 4);
		end if;
	end process;
end main; 

