----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:29:19 07/13/2014 
-- Design Name: 
-- Module Name:    test1 - Behavioral 
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

entity test1 is
		 Port ( RST : in  STD_LOGIC;
           CLK : in  STD_LOGIC; 
            
			  PCupdate : in  STD_LOGIC;
           PCnew : in  STD_LOGIC_VECTOR (15 downto 0);
           MPC : in  STD_LOGIC_VECTOR (15 downto 0);
           IR : out  STD_LOGIC_VECTOR (15 downto 0);
           PC : out  STD_LOGIC_VECTOR (15 downto 0));
end test1;

architecture Behavioral of test1 is
component number1 
    Port ( CLK : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           T1 : out  STD_LOGIC;
           T2 : out  STD_LOGIC;
           T3 : out  STD_LOGIC;
           T4 : out  STD_LOGIC);
		end component;
		component quzhi 
    Port ( PCupdate : in  STD_LOGIC;
           PCnew : in  STD_LOGIC_VECTOR (15 downto 0);
           CS0 : in  STD_LOGIC;
           RST : in  STD_LOGIC;
           MPC : in  STD_LOGIC_VECTOR (15 downto 0);
           IR : out  STD_LOGIC_VECTOR (15 downto 0);
           PC : out  STD_LOGIC_VECTOR (15 downto 0));
		end component;
	
		signal T1,T2,T3,T4: STD_LOGIC;
begin
element1:component number1 port map(CLK,RST,T1,T2,T3,T4);
element2: component quzhi port map(PCupdate,PCnew,T1,Rst,MPC,IR,PC);
--element6:component ctrl_M port map(PC,ADDR,OP,dataout,T1,T3,datain,MPC,DBUS,ABUS,nMREQ,nRD,nWR,nBHE,nBLE);
end Behavioral;

