----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:56:07 07/02/2014 
-- Design Name: 
-- Module Name:    lab5 - Behavioral 
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

entity lab5 is
    Port ( DATA : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           CSN : in  STD_LOGIC;
           WRN : in  STD_LOGIC;
           RDN : in  STD_LOGIC;
           A : in  STD_LOGIC_VECTOR (1 downto 0);
           INTN : out  STD_LOGIC;
           D : inout  STD_LOGIC_VECTOR (7 downto 0));
end lab5;

architecture Behavioral of lab5 is
component ctrl 
port(
	d9, d11 : in std_logic;
	sq7, sq6 : in std_logic;
	rq : in std_logic_vector(7 downto 0);
	clrn : inout std_logic;
   start : out std_logic;
	serial, clk : in std_logic;
	csn, wrn, rdn : in std_logic;
	addr : in std_logic_vector(1 downto 0);
	data : inout std_logic_vector(7 downto 0);
	intn : out std_logic
	);
end component;
component decode4 
port(
	d : in std_logic_vector(3 downto 0);
	enable : in std_logic;
	q8, q9, q11 : out std_logic
	);
end component;

component reg8 
port(
	clrn, clk : in std_logic;
	d : in std_logic_vector(7 downto 0);
	q : out std_logic_vector(7 downto 0)
	);
end component;
component sreg 
port(
	clk, clrn, serial : in std_logic;
	q : out std_logic_vector(7 downto 0)
	);
end component;
component count4 
port(
	clk : in std_logic;
	clrn : in std_logic;
	q : out std_logic_vector(3 downto 0)
	);
end component;
	signal c:STD_LOGIC_VECTOR(3 downto 0);
	signal start,t9,t11,clrn:std_logic;
	signal t8:STD_LOGIC;
	signal tdata,treg:std_logic_vector(7 downto 0);
begin
  elelment1:component ctrl port map(t9,t11,treg(7),treg(6),tdata,clrn,start,DATA,clk,CSN,WRN,RDN,a,D,intn);

	elelment2:component count4 port map(clk,start,c);
	elelment3:component decode4 port map(c,start,t8,t9,t11);
	elelment4:component sreg port map(clk,start,data,treg);

	elelment5:component reg8 port map(clrn,t8,treg,tdata);
end Behavioral;

