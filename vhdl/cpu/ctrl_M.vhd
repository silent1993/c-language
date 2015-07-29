----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:44:00 07/08/2014 
-- Design Name: 
-- Module Name:    ctrl_M - Behavioral 
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

entity ctrl_M is
    Port ( PC : in  STD_LOGIC_VECTOR (15 downto 0);
           ADDR : in  STD_LOGIC_VECTOR (15 downto 0);
           OP : in  STD_LOGIC_VECTOR (4 downto 0);
           datain : in  STD_LOGIC_VECTOR (7 downto 0);
			  CS0: in STD_LOGIC;
			  CS2: in STD_LOGIC;
           MADDR : out  STD_LOGIC_VECTOR (7 downto 0);
           MPC : out  STD_LOGIC_VECTOR (15 downto 0);
           DBUS : inout  STD_LOGIC_VECTOR (15 downto 0);
           ABUS : out  STD_LOGIC_VECTOR (15 downto 0);
           nMREQ : out  STD_LOGIC;
           nRD : out  STD_LOGIC;
           nWR : out  STD_LOGIC;
           nBHE : out  STD_LOGIC;
           nBLE : out  STD_LOGIC
			  );
end ctrl_M;

architecture Behavioral of ctrl_M is

begin
quzhi:process(PC,DBUS,datain,cs0,cs2,OP,ADDR)
begin
if(CS0='1')then
	ABUS<=PC;
	MPC<=DBUS;
	DBUS<="ZZZZZZZZZZZZZZZZ";
	nRD<='0';
	nMREQ<='0';
	nWR<='1';
	nBHE<='0';
	nBLE<='0';
elsif(CS2='1')then
		
			if(OP="10001")then
					ABUS<=ADDR;
				DBUS(7 downto 0)<=datain;
				nRD<='1';
				nWR<='0';
				nMREQ<='0';
				nBHE<='1';
				nBLE<='0';
			elsif(OP="10011")then 
				ABUS<=ADDR;
				MADDR<=DBUS(7 downto 0);
				DBUS<="ZZZZZZZZZZZZZZZZ";
				nRD<='0';
				nWR<='1';
				nMREQ<='0';
				nBHE<='1';
				nBLE<='0';
			end if;
end if;

end process;
end Behavioral;

