----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:23:39 07/02/2014 
-- Design Name: 
-- Module Name:    reg8 - Behavioral 
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

entity reg8 is
port(
	clrn, clk : in std_logic;
	d : in std_logic_vector(7 downto 0);
	q : out std_logic_vector(7 downto 0)
	);
end reg8 ;

architecture main of reg8 is
begin
	process(clk, clrn)
	begin
		if clrn = '0' then
			q <= "00000000";
		elsif clk = '1' and clk'event then 
			q <= d;
		end if;
	end process;
end main;

 
