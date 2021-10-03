SELECT empregados.cpf, empregados.enome, departamentos.dnome FROM empregados,
       departamentos WHERE empregados.dnumero = departamentos.dnumero AND
       empregados.cpf NOT IN (SELECT trabalha.cpf_emp FROM trabalha)
       ORDER BY empregados.cpf;