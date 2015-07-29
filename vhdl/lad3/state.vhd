----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:23:28 06/27/2014 
-- Design Name: 
-- Module Name:    state - Behavioral 
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

entity state is
    Port ( read_write : in  STD_LOGIC;
           ready : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           oe : out  STD_LOGIC;
           we : out  STD_LOGIC);
end state;

architecture Behavioral of state is
type sta is(staA,staB,staC,staD);
signal pr_sta,nx_sta:sta;

begin
B1:process(ready,clk)
	begin
	if(ready='1') then
		pr_sta<=staA;
	elsif(clk'event and clk='1') then
		pr_sta<=nx_sta;
	end if;
	end process;
	
B2:process(read_write,ready,pr_sta)
		begin
		case pr_sta is
			when staD=>
				oe<='0';
				we<='0';
			if(ready='1') then
				nx_sta<=staD;
			else 
					if(read_write='1') then
					nx_sta<=staC;
					else
					nx_sta<=staB;
					end if;
			end if;
			when staB=>
				oe<='0';
				we<='1';
				if(ready='1') then
					nx_sta<=staD;
				else
					nx_sta<=staB;
				end if;
			when staC=>
				oe<='1';
				we<='0';
				if(ready='1') then
					nx_sta<=staD;
				else
					nx_sta<=staC;
				end if;
			when staA=>
				if(ready='1') then
					nx_sta<=staD;
				else
					nx_sta<=staA;
				end if;
			end case;
		end process;


end Behavioral;
