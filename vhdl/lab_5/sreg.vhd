----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:23:06 07/02/2014 
-- Design Name: 
-- Module Name:    sreg - Behavioral 
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

entity sreg is
port(
	clk, clrn, serial : in std_logic;
	q : out std_logic_vector(7 downto 0)
	);
end sreg ;

architecture main of sreg is
	signal t : std_logic_vector(7 downto 0);
begin
	process(clk, clrn)
	begin
		if clrn = '0' then
			t <= "00000000";
		elsif clk = '1' and clk'event then 
			t(7) <= serial;
			t(6 downto 0) <= t(7 downto 1);
		end if;

	end process;
	q <= t;
end main;

